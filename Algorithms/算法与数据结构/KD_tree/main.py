# coding=utf8
import sys
import math
import time
import matplotlib.pyplot as plt
import numpy as np

#定义节点类型
class KD_node:
    def __init__(self, point=None, split=None, left=None, right=None):
        '''
        :param point: 数据点的特征向量
        :param split: 切分的维度
        :param left: 左儿子
        :param right: 右儿子
        '''
        self.point = point
        self.split = split
        self.left = left
        self.right = right

def splitIndicator(arrayList):
    '''
    因为采用标准分割策略(分割维具有最大延展度)，所以这里求的指标(indicator)就是延展度
    :param arrayList: 所有数据某一维的向量
    :return: 返回延展度
    '''
    array = np.array(arrayList)
    return array.max() - array.min()

def createKDTree(root, data_list):
    '''
    :param root: 输入一个根节点，以此建树
    :param data_list: 数据列表
    :return: 返回根节点
    '''
    LEN = len(data_list)
    if LEN == 0:
        return
        # 数据点的维度
    dimension = len(data_list[0]) #- 1 #去掉了最后一维标签维
    # 方差
    max_indicator = 0
    # 最后选择的划分域
    split = 0
    for i in range(dimension):
        ll = []
        for t in data_list:
            ll.append(t[i])
        indicator = splitIndicator(ll) # 计算出在这一维分割的指标indicator大小
        if indicator > max_indicator:
            max_indicator = indicator
            split = i
            # 根据划分域的数据对数据点进行排序
    data_list = list(data_list)
    data_list.sort(key=lambda x: x[split]) #按照在切分维度上的大小进行排序
    data_list = np.array(data_list)
    # 选择下标为len / 2的点作为分割点
    point = data_list[LEN // 2]
    root = KD_node(point, split)
    root.left = createKDTree(root.left, data_list[0:(LEN // 2)])#递归的对切分到左儿子和右儿子的数据再建树
    root.right = createKDTree(root.right, data_list[(LEN // 2 + 1):LEN])
    return root

def computeDist(pt1, pt2):
    '''
    :param pt1: 特征向量1
    :param pt2: 特征向量2
    :return: 两个向量的欧氏距离
    '''
    sum_dis = 0.0
    min_length = min(len(pt1), len(pt2))
    for i in range(min_length):
        sum_dis += (pt1[i] - pt2[i]) ** 2
    #实现的欧氏距离计算，效率很低的版本，可以改成numpy的向量运算
    return math.sqrt(sum_dis)


def findNN(root, query):
    '''
    nearest neighbor search
    :param root: 建立好的KD树的树根
    :param query: 查询数据(维度应该小1)
    :return: 与这个数据最近的前三个节点
    '''
    # 初始化为root的节点
    NN = root.point
    min_dist = computeDist(query, NN)
    nodeList = []
    temp_root = root
    min_point = root.point
    # dist_list = [temp_root.point, None, None] #用来存储前三个节点
    ##二分查找建立路径
    while temp_root:
        nodeList.append(temp_root) #对向下走的路径进行压栈处理
        dd = computeDist(query, temp_root.point) #计算当前最近节点和查询点的距离大小
        if min_dist > dd:
            NN = temp_root.point
            min_dist = dd
            min_point = temp_root.point
            # 当前节点的划分域
        temp_split = temp_root.split
        if query[temp_split] <= temp_root.point[temp_split]:
            temp_root = temp_root.left
        else:
            temp_root = temp_root.right

    ##回溯查找
    while nodeList:
        back_point = nodeList.pop()
        back_split = back_point.split
        if abs(query[back_split] - back_point.point[back_split]) < min_dist: 
            #当查询点和回溯点的距离小于当前最小距离时，另一个区域有希望存在更近的节点
            #如果大于这个距离，可以理解为假设在二维空间上，直角三角形的直角边已经不满足要求了，那么斜边也一定不满足要求
            if query[back_split] < back_point.point[back_split]: # 刚才走的左边，现在看右边
                temp_root = back_point.right
            else: # 刚才走的右边，现在看下左边
                temp_root = back_point.left
            if temp_root:
                # curPoint, curDist = findNN(temp_root, query)
                nodeList.append(temp_root)
                curDist = computeDist(query, temp_root.point)
                if min_dist > curDist:
                    min_dist = curDist
                    # min_point = curPoint
                    min_point = temp_root.point
    return (min_point, min_dist)

def pre_data(ori_list):
    '''
    选取需要的几列，然后规范化
    '''
    result = []
    for line in ori_list:
        line = line.split(',')
        # [23, 31]
        line = line[23:32] # + line[-1:] 不要标签列
        line = [float(i) for i in line]
        result.append(line)
    result = np.array(result)
    min_arr = result.min(0)
    max_arr = result.max(0)
    div = max_arr - min_arr
    for i in range(len(div)):
        if div[i] == 0:
            div[i] = 1 if min_arr[i]==0 else min_arr[i]
    result /= div
    return result

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("please pass in normal_data_path and smurf_data_path")
    # 6:2:2 划分正常数据
    
    normal_data = open(sys.argv[1]).readlines()
    smurf_data = open(sys.argv[2]).readlines()
    
    split1 = int(len(normal_data)/5*3)
    split2 = int(len(normal_data)/5*4)

    norm60_train = normal_data[:split1]
    norm20_train = normal_data[split1:split2]
    norm20_test = normal_data[split2:]

    norm60_train = pre_data(norm60_train)
    norm20_train = pre_data(norm20_train)
    norm20_test = pre_data(norm20_test)
    smurf_data = pre_data(smurf_data)
    print('finish preprocessing data...')

    # train_data_path = sys.argv[1]
    # test_data_path = sys.argv[2]
    
    print('creating kd_tree')
    root = KD_node()
    root = createKDTree(root, norm60_train)
    print('kd_tree created')

    max_dis = .80 # 最后训练出最大距离
    norm_dis_list = []
    for query in norm20_train:
         _, dis = findNN(root, query)
         norm_dis_list.append(dis)
        #  if dis > max_dis:
        #      max_dis = dis
            #  break
    norm_dis_list.sort()
    plt.plot(range(len(norm_dis_list)), norm_dis_list, marker='.')
    plt.show()
    # print('get max_norm_dis:', max_dis) # get max_norm_dis: 1.2709103997891982
    max_dis = input("input max distance between X and known closest normal points:\n\t")
    max_dis = float(max_dis)

    norm_err = 0
    ddos_err = 0
    norm_test_total = len(norm20_test)
    smurf_test_total = len(smurf_data)
    total = norm_test_total + smurf_test_total

    cnt=0
    for query in norm20_test:
        _, dis = findNN(root, query)
        if dis > max_dis:
            print(f'norm dis: {dis}')
            norm_err += 1 # 正常点被判定为异常
    print(f'finish testing norm, norm_err: {norm_err}/{norm_test_total}')

    cnt=0
    for query in smurf_data:
        _, dis = findNN(root, query)
        # print('smurf_test dis:', dis)
        if dis <= max_dis:
            print(f'smurf dis: {dis}')
            ddos_err += 1
        cnt+=1
        if cnt % 10000 == 0:
            print('smurf_test_cnt:', cnt, 'smurf_test_total:', smurf_test_total, f'ddos_err: {ddos_err}/{smurf_test_total}')
    print('finish testing smurf')

    print(f'norm_err: {norm_err}/{norm_test_total} {norm_err/norm_test_total}')
    print(f'ddos_err: {ddos_err}/{smurf_test_total} {ddos_err/smurf_test_total}')
    print(f'total_err: {norm_err+ddos_err}/{total} {norm_err+ddos_err/total}')
    print('precisoin:', 1 - (norm_err+ddos_err)/total)