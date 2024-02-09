/*
Bellman-Ford(int v)
	d[i] = inf for each vertex i
	d[v] = 0
	for step = 1 to n
		for all edges like e
			i = e.first // first end
			j = e.second // second end
			w = e.weight
			if d[j] > d[i] + w
				if step == n
					then return "Negative cycle found"
				d[j] = d[i] + w
*/
