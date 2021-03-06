'use strict';

/* Directives */


angular.module('CodeAssist.directives', [])
.directive('scrollPosition', function($window) {
  return {
    scope: {
      scroll: '=scrollPosition'
    },
    link: function(scope, element, attrs) {
      var windowEl = angular.element($window);
      var handler = function() {
        scope.scroll = windowEl.scrollTop();
      }
      windowEl.on('scroll', scope.$apply.bind(scope, handler));
      handler();
    }
  };
})
.directive('ngPrism',function ($interpolate, $compile) {
        "use strict";
        return {
            restrict: 'E',
            template: '<pre><code ng-transclude></code></pre>',
            replace: true,
            transclude: true,
            link: function (scope, elm) {
						var tmp = $interpolate(elm.find('code').text())(scope);
						Prism.highlightElement(tmp);
            }
        };
    });

