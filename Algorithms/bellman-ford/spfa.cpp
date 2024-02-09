// bellman-ford的队列优化版本
// SPFA (Shortest Path Faster Algorithm)

/*
SPFA(v):
	d[i] = inf for each vertex i
	d[v] = 0
	queue q
	q.push(v)
	while q is not empty
		u = q.front()
		q.pop()
		for each i in adj[u]
			if d[i] > d[u] + w(u,i)
				then d[i] = d[u] + w(u,i)
				if i is not in q
					then q.push(i)
*/