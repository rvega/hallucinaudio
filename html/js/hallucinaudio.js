// Set this to true if you want to debug in a standalone web browser
DEBUG = false;

//====================//
//  INIT PLAY BUTTON  //
//====================//
function initPlay(){
  $('#play').on('click tap', function(e){
    var src = $('#playimg').attr('src');
    if(src == 'img/play.png'){
      PureData.sendFloat('1', 'play');
      $('#playimg').attr('src','img/pause.png') 
    }
    else{
      PureData.sendFloat('0', 'play');
      $('#playimg').attr('src','img/play.png') 
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
    'width': '170',
    'height': '133'
  };

  
  var opts2;

  // TEMPO
  opts2 = $.extend({'change': function(v){
      PureData.sendFloat(v, 'tempo');
  }}, options);
  $("#tempo").knob( opts2 );

  // GAIN
  opts2 = $.extend({'change': function(v){
      PureData.sendFloat(v/10, 'mic-gain');
  }}, options);
  $("#gain").knob( opts2 );
  
  // VOLUME
  opts2 = $.extend({'change': function(v){
      PureData.sendFloat(v/10, 'volume');
  }}, options);
  $("#volume").knob( opts2 );
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
  //TODO: prevent screen rotation
  document.addEventListener('orientationchange', function(e) { e.preventDefault(); }, false);

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
