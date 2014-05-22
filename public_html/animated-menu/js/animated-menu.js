$(document).ready(function(){
	
	//Fix Errors - http://www.learningjquery.com/2009/01/quick-tip-prevent-animation-queue-buildup/
	
	//Remove outline from links
	$("ul.nav a").click(function(){
		$(this).blur();
	});
	
	//When mouse rolls over
	$("ul.nav li").mouseover(function(){
		$(this).stop().animate({height:'150px'},{queue:false, duration:700, easing: 'easeOutCirc'})
	});
	
	//When mouse is removed
	$("ul.nav li").mouseout(function(){
		$(this).stop().animate({height:'50px'},{queue:false, duration:700, easing: 'easeInOutCirc'})
	});
	
});

