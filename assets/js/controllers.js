'use strict';

/* Controllers */

angular.module('CodeAssist.controllers', []).
  
controller('AppController', function ($scope, $http, $location, $sce) {

	// Fetch loaded algorithms
	$scope.algorithms = [];
	$http.get('algorithms/index.js').
	success(function(data, status, headers, config) {
		$scope.algorithms = data;
	});

	// Get file extension based on a language
	var mapExtension = function(language) {
		var array = {"C++": "cpp"};

		return array[language];
	}

	// Append the source codes of the current algorithm to the scope
	var updateSourceCodes = function(languages) {
		if (languages.length == 0) {
			// Patch to update colours in PrismJS! Fix it
			setTimeout(function () {
				  $scope.$apply(function () {
						Prism.highlightAll();
				  });
			}, 10);

			// Move browser scroll to algorithm section
			$scope.scrollTo("algorithm");
			return;
		}

		// If there are still languages to add, process them
		var language = languages.pop();
		var extension = mapExtension(language);
		var normalized = $scope.current.normalized;

		// Fetch file and save source code
		$http.get("algorithms/" + normalized + '/' + normalized + '.' + extension).
		success(function(data, status, headers, config) {
			$scope.current.sources.push({language: language, code: data});
			updateSourceCodes(languages);
		});
	}

	// Search algorithm from user input 
	$scope.getAlgorithm = function() {
		// Initialize
		$scope.current = {name: "", languages: [], description: "", complexity: {}};
		var n = $scope.algorithms.length;
		var i = 0;

		var algorithm_name = $scope.input_algorithm;

		// Iterate until finding algorithm or no more algorithms in the list
		while (i < n) {
			if ($scope.algorithms[i].name == algorithm_name) {
				angular.copy($scope.algorithms[i],$scope.current);
				$scope.current.sources = [];
				$scope.current.description = $sce.trustAsHtml($scope.current.description);

				console.log($scope.current);

				// Normalize name to get folder
				$scope.current.normalized = $scope.current.name.toLowerCase().replace(' ','_');
	
				// Load available source codes of the algorithm
				updateSourceCodes($scope.current.languages);

				break;
			}
			i++;
		}
	}

	// Scroll to anchor
	$scope.scrollTo = function(anchor) {
		$("body").animate({scrollTop: $("#"+anchor).offset().top}, "slow");
	}

});
