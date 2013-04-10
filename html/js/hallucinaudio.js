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
});
