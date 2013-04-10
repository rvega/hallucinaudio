//====================//
//  INIT PLAY BUTTON  //
//====================//
function initPlay(){
  $('#play').click(function(){
    var src = $('#play').children('img').first().attr('src');
    if(src == 'img/play.png'){
      $('#play').children('img').first().attr('src','img/pause.png') 
    }
    else{
      $('#play').children('img').first().attr('src','img/play.png') 
    }
  })
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

//===========//
//  ON LOAD  //
//===========//
$(function() {
  initKnobs();
  initPlay();
});
