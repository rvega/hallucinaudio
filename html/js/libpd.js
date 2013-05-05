PureData = {
  // var lastKey;

  initPD: function(){
    //navigator.notification.alert('Trying to notify', null, 'Title', 'Button');
    cordova.exec(
     function(e){
       // Success.
       navigator.notification.alert('Success', null, 'Title', 'Button');
     }, 
     
     function(e){ 
       // Error.
       navigator.notification.alert('Error', null, 'Title', 'Button');
     }, "PureData", "initPD", []);
 }
}
