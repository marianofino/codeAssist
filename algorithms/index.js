[
	{
		"name": "Mergesort",
		"languages": ["C++"],
		"description": "Mergesort is a divide and conquer algorithm that was invented by John von Neumann in 1945. Conceptually, a merge sort works as follows:<ol><li>Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).</li><li>Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.</li></ol>",
		"complexity": {
			"Worst case": "O(n log n)",
			"Best case": "O(n log n)",
			"Average case": "O(n log n)"
		},
		"source": "http://en.wikipedia.org/wiki/Merge_sort",
		"video_overview": "<iframe width=\"100%\" height=\"360\" src=\"//www.youtube.com/embed/EeQ8pwjQxTM\" frameborder=\"0\" allowfullscreen></iframe>",
		"links": null
	},
	{
		"name": "Quicksort",
		"languages": ["C++"],
		"description": "Quicksort is a divide and conquer algorithm developed in 1960 by Tony Hoare. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays. The steps are:<ol><li>Pick an element, called a pivot, from the array.</li><li>Reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.</li><li>Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.</li></ol>",
		"complexity": {
			"Worst case": "O(n^2)",
			"Best case": "O(n log n)",
			"Average case": "O(n log n)"
		},
		"source": "http://en.wikipedia.org/wiki/Quicksort",
		"video_overview": "<iframe width=\"100%\" height=\"360\" src=\"//www.youtube.com/embed/aQiWF4E8flQ\" frameborder=\"0\" allowfullscreen></iframe>",
		"links": {"Complexity analysis": "http://www.cise.ufl.edu/class/cot3100fa07/quicksort_analysis.pdf"}
	}
]
