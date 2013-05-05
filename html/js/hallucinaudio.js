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
  $(".knob").knob({
    'fgColor': '#ffec03',
    'inputColor': '#ffec03',
    'bgColor': '#444444',
    'angleOffset': '-125',
    'angleArc': '250',
    'width': '120',
    'height': '94'
  });
}

//========//
//  MAIN  //
//========//
function main(){
  initKnobs();
  initPlay();
  PureData.initPD();
};

if(DEBUG){
  $(document).ready(main);
}
else{
  document.addEventListener('deviceready', main, false);
}
