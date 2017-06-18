angular.module('starter.controllers', ['ngCordova'])

.controller('AppCtrl', function($scope,$state, $ionicModal, $timeout,$cordovaDeviceMotion,Service) {

  $scope.login = function(data) {
    localStorage.setItem("ip",data.ip);
    $state.go("app.playlists");
  }

  $scope.setRotate = function (distance) {
    console.log(distance);
     $scope.text = distance;

    Service.sendRotate(distance).then(function (response) {
      if(response == 1){
        $scope.status = "Komut Gönderildi";
      }else{
        $scope.status = "Komut gönderilirken bi hata oluştu.Tekrar deneyiniz";
      }

      $timeout(function() {
        $scope.status = "";
      }, 500);
        
    }, function (response) {
      
    });

  }


  


})

.controller('PlaylistsCtrl', function($scope) {
  
})

.controller('PlaylistCtrl', function($scope, $stateParams) {
});
