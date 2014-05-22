<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
   <title> Week 06 Example Script </title>
    <?php require_once 'utils.php' ?>

    <?php 
       // the head tag is a good place to put function definitions

       // a sample function definition and function call
       function test ( $str1,  $str2, $str3, $num1, $num2 )
       {
           $mystring = $str1." ".$str2." ".$str3;
           echo "\t\t\t".$mystring."<br />"; 
           return $num1 * $num2; 
       }
 
       //StringWordCount takes a string input, and returns a word count
       function StringWordCount ($input, &$count)
       {
	   $count = str_word_count($input);
	   return $count;
       }

       function formatEmail ($uname, $provider, $domain)
       {
	   $formatted = $uname . "@" . $provider . "." . $domain;
	   return $formatted;
       }
    ?>
  </head>

<body>
<div id='wrapper' >
   <div id='left' >
      <?php include_once 'left.php' ?>
   </div>

      <div id='main'>
      
          <h3> Week 7: Using Functions and Server Side Includes </h3>
          
          <hr />
          
          <h4>Description</h4>
          <p>
           With PHP you can easily create a consistent page layout
           and format style across all your web pages. You simply generate 
           your pages using PHP and include the stylesheets and other
           components you want to appear on all pages with server side include 
           statements.
          </p>
          <p>
          For example, the page you are looking at (week07.php) includes 
          two other files. The first (left.php) contains the A HREF tags
          you see in the green area on the left. The second (utils.php) 
          contains a LINK tag to the stylesheet and a META tag.
          Note, that there is no php in the utils.php file, 
          although it has the extension php. You can certainly put php in
          the file if you wish -- php function definitions that are called
          frequently are often included in util files. Note the location
          of the include statements. If the purpose of the php include file
          is to generate HTML tags, then the include statement should be
          where you want those tags to be in the page.
          </p> <pre>
        &lt;?php require_once 'utils.php' ?>   // within the head tag 
        &lt;?php include_once 'left.php' ?>    // where the left menu should be
    </pre>
    Testing function call:<br/>
    <?php 
       $n1 = 17;
       $n2 = 13;
       $result = test("hello","and","goodbye", $n1, $n2 );
       echo "\t\t\t".$result."<br />";
    ?>

    <?php echo "Today is " . displayDate() . "<p>&nbsp</p>";?>
    
<?php 
       $numWords = 0;
       
       $longParagraph = "Today, mainstream usage of 'hacker' mostly refers to computer criminals, due to the mass media usage of the word since the 1980s. 
	   This includes what hacker slang calls 'script kiddies' people breaking into computers using programs written by others, with very little knowledge about the way they work. 
	   This usage has become so predominant that the general public is unaware that different meanings exist. 
	   While the self-designation of hobbyists as hackers is acknowledged by all three kinds of hackers, and the computer security hackers accept all uses of the word, people from the programmer subculture consider the computer intrusion related usage incorrect, and emphasize the difference between the two by calling security breakers 'crackers' (analogous to a safecracker).";

       echo "Testing StringWordCount() with variables:<br>";
       echo "Your string includes " . 
	   StringWordCount($longParagraph, $numWords) .
	   " words. Thanks for playing :)<p>&nbsp</p>";
       echo "Testing StringWordCount() with literals:<br>";
       echo "Your string includes " . 
	   StringWordCount("This is a short little test string", $numWords) .
	   " words. Thanks for playing :)<p>&nbsp</p>";

       $user = "netRaider";
       $email = "fakeprovider";
       $dom = "com.cn";

       echo 'My user name: ' . $user . '<br>
	     My email provider: ' . $email . '<br>
	     Domain for email provider ' . $dom . '<br>
	     My fully formed email address: ' . 
	     formatEmail($user, $email, $dom) . '<p>&nbsp;</p>';
 	
       echo 'My user name: netRaider<br>
	     My email provider: fakeprovider<br>
	     Domain for email provider com.cn <br>
	     My fully formed email address: ' . 
	     formatEmail('netRaider', 'fakeprovider', 'com.cn' );
 

?>


    </div>  <!-- end main div -->
 </div>  <!-- end wrapper div -->
</body>
</html>
