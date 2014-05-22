
var deckTop = 0;
var swapCount = 0;

//  shuffle deck d   *FINISH*
function shuffle ( d )
{
  var i = 0;
  var j = 0;
  
  for (var k=1; k<= 150; k++)
  {
  i = Math.floor((Math.random() * 50) + 1);
  j = Math.floor((Math.random() * 50) + 1);
  swapCard(d,i,j);
  deckTop = 0;
  }
  }


// initialize deck d with 54 card images - should call this ONCE only 
function init ( d )
{
  var img_fname;
  var num;
 
  // load the deck with 54 card images  - the last two are jokers
  for (var i = 0; i < 53; i++)
  {
    num = i + 1;     
    img_fname="http://www.cs.csub.edu/~donna/cs211/Final/"+num+"."+"png";
    d[i] = new Image();
    d[i].src = img_fname;
  }
  
}

// swap card i with card j in deck d 
function swapCard(d,i,j)
{
  var tmpimg = new Image();
  tmpimg.src = d[i].src;
  d[i].src = d[j].src;
  d[j].src = tmpimg.src
  
}

// deal 5 cards from deck d  *FINISH* 
function deal ( d )
{
	if(deckTop<49)
	{
	document.card1_img.src = deck[deckTop].src;
	deckTop++;
	document.card2_img.src = deck[deckTop].src;
	deckTop++;
	document.card3_img.src = deck[deckTop].src;
	deckTop++;
	document.card4_img.src = deck[deckTop].src;
	deckTop++;
	document.card5_img.src = deck[deckTop].src;
	deckTop++;
	}
	else
	{deckTop = 0;}

}

//Exchange card c with card from deck
function exchange(i)
		{ 
			
		if (swapCount<=2)
			{
			i.src = deck[deckTop].src;
			deckTop++;
			swapCount++;
			}
		else
			{
			alert("You can't swap anymore cards");
			}
		}
		
function startgame()
				{
				top_card = 0;
				deckTop = 0;
				swapCount = 0;
				document.card1_img.src = deck[52].src;
				document.card2_img.src = deck[52].src;
				document.card3_img.src = deck[52].src;
				document.card4_img.src = deck[52].src;
				document.card5_img.src = deck[52].src;
				}

