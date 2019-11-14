import sys

# kddcup.data_10_percent
# 0,icmp,ecr_i,SF,1032,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,316,316,0.00,0.00,0.00,0.00,1.00,0.00,0.00,148,3,0.02,0.02,0.02,0.00,0.00,0.00,0.00,0.00,smurf.
# 0,tcp,http,SF,181,5450,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,8,8,0.00,0.00,0.00,0.00,1.00,0.00,0.00,9,9,1.00,0.00,0.11,0.00,0.00,0.00,0.00,0.00,normal.
def get_smurf_and_normal(ori_path):
    with open('smurf.txt', 'w') as smurf_file, open('normal.txt', 'w') as normal_file, open(ori_path, 'r') as f:
        line = f.readline()
        while line:
            line_arr = line.split(',')
            gener = line_arr[-1].strip()
            if gener == 'smurf.':
                smurf_file.write(line)
            elif gener == 'normal.':
                normal_file.write(line)
            line = f.readline()

if __name__ == "__main__":
    # get_smurf_and_normal(sys.argv[0])
    if len(sys.argv) < 2:
        print("please add data_path as the first argument")
    ori_path = sys.argv[1]
    print('Processing file:', sys.argv[1])
    get_smurf_and_normal(sys.argv[1])
