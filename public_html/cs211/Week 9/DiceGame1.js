window.onload=function(){
Nifty("div.playerArea", "big");
}

//Overall Scores
var humGameTot = 0;
var compGameTot = 0;

//Game Results
var vicHum = 0;
var vicComp = 0;
var tie = 0;




function roll()
{
  var result = 0;
  result = Math.floor((Math.random() * 6) + 1);
  return result;
}

function play()
{
  // create dice array
  var humanDice = new Array();
  var computerDice = new Array();
  
  // totals
  var humanTotal = 0;
  var computerTotal = 0;
  
  // output
  var out = "";
  
  // roll the dice
  for (var i = 0; i < 6; i++)
  {
    humanDice[i] = roll();
    humanTotal += humanDice[i];
    
    computerDice[i] = roll();
    computerTotal += computerDice[i];
  }
  
  //Accumulates the total score for the Game
  humGameTot += humanTotal;
  compGameTot += computerTotal;
  
  // display human dice
  out = displayDice(humanDice);
  document.getElementById('humanDice').innerHTML = out;
  
  // display computer dice
  out = displayDice(computerDice);
  document.getElementById('computerDice').innerHTML = out;
  
  document.getElementById('humanTotal').innerHTML = humanTotal;
  document.getElementById('computerTotal').innerHTML =  computerTotal;
  document.getElementById('humGameTot').innerHTML = humGameTot;  
  document.getElementById('compGameTot').innerHTML =  compGameTot; 
  
  if (humanTotal > computerTotal)
  {
    document.getElementById('humanTotal').className = 'total winner';
    document.getElementById('computerTotal').className = 'total loser';
  }
  else if (computerTotal > humanTotal)
  {
    document.getElementById('humanTotal').className = 'total loser';
    document.getElementById('computerTotal').className = 'total winner';
  }
  else
  {
    document.getElementById('humanTotal').className = 'total';
    document.getElementById('computerTotal').className = 'total';
  }

}

function stop()
{
 
 //while (humGameTot <= 100)
 //{
 //humGameTot-compGameTot;
 //return gameRes;
 //}

 //Human Win
  if( (humGameTot > compGameTot) && (humGameTot <= 100) )
		{
		vicHum++;
		changeTxt("humWin", vicHum);
		}
  
  else if ( (humGameTot <= 100) && (compGameTot > 100) )
		{
		vicHum++;
		changeTxt("humWin", vicHum);
		}
  //Computer Win	
  else if ( (compGameTot > humGameTot) && (compGameTot <= 100) )
		{
		vicComp++;
		changeTxt("compWin", vicComp);
		}
		
  else if ( (compGameTot <= 100) && (humGameTot > 100) )
		{
		vicComp++;
		changeTxt("compWin", vicComp);
		}
		
  //Tie
  else if ( (humGameTot <= 100) && (compGameTot <= 100) && (humGameTot == compGameTot) )
		{
		tie++;
		changeTxt("draw", tie);
		}
		
 else 
		{
		alert("You busted sucka! Play again.")
		}
  
	
   //else if( (humGameTot < compGameTot) && (humGameTot <= 100) )
		//{
		//vicComp++;
		//changeTxt("compWin", vicComp);
		//}
	
	//else if( (compGameTot > humGameTot) && (
	
		
		humanTotal=0;
		computerTotal=0;
		humGameTot=0;
		compGameTot=0;
		document.getElementById('humanTotal').innerHTML = humanTotal;
		document.getElementById('computerTotal').innerHTML = computerTotal;
		document.getElementById('humGameTot').innerHTML = humGameTot;
		document.getElementById('compGameTot').innerHTML = compGameTot;
		
 }

function displayDice(dice)
{
  var out = "";
  for (var i = 0; i < dice.length; i++)
  {
    out += "<img src='die" + dice[i] + ".png'/>";
  }
  
  return out;
}
