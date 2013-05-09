// Set this to true if you want to debug in a standalone web browser
DEBUG = false;

//====================//
//  INIT PLAY BUTTON  //
//====================//
function initPlay(){
  $('#play').on('click tap', function(e){
    var src = $('#play').children('img').first().attr('src');
    if(src == 'img/play.png'){
      $('#play').children('img').first().attr('src','img/pause.png') 
    }
    else{
      $('#play').children('img').first().attr('src','img/play.png') 
    }
  });
}

//==============//
//  INIT KNOBS  //
//==============//
function initKnobs(){
  var options = {
    'fgColor': '#ffec03',
    'inputColor': '#ffec03',
    'bgColor': '#444444',
    'angleOffset': '-125',
    'angleArc': '250',
    'width': '120',
    'height': '94'
  };

  
  var freqOpts = $.extend({'change': function(v){
      PureData.sendFloat(v, 'frequency');
  }}, options);
  $("#frequency").knob( freqOpts );

  var gainOpts = $.extend({'change': function(v){
      PureData.sendFloat(v/100, 'gain');
  }}, options);
  $("#gain").knob( gainOpts );
}

//===========//
//  INIT PD  //
//===========//
function showAudioError(error){
  console.log(error); 
  navigator.notification.alert('I can\'t start audio playback :(', null, 'Oh no!', 'Grrr!');
}

function initPD(){
  PureData.configurePlayback(44100, 2, true, false, null, function(error){ 
    showAudioError(error);
  });

  PureData.openFile('./pd', 'Hallucinaudio.pd', null, function(error){ 
    showAudioError(error);
  });

  PureData.setActive(true, null, function(error){ 
    showAudioError(error);
  });

}

//========//
//  MAIN  //
//========//
function main(){
  initKnobs();
  initPlay();
  initPD();
};

if(DEBUG){
  $(document).ready(main);
}
else{
  document.addEventListener('deviceready', main, false);
}
