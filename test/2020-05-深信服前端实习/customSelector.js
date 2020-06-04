function customQuery(query) {
	if (Object.prototype.toString.call(query) !== '[object String]') {
		return null
	}
	const arr = []
	let i = 0, j = 0
	while (i < query.length) {
		if (query[i] === '.') {
			j = i+1
			while (j < query.length && query[j] !== ' ' && query[j] !== '.') {
				j++
			}
			arr.push(query.slice(i+1, j))
			i = j-1
		}
		i++
	}

	let target = null

	try {
		let el
		for (let queryStr of arr) {
			el = document.getElementsByClassName(queryStr)
		}
	} catch (e) {
		target = null
	}

	return target
}

