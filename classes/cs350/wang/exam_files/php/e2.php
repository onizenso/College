<html>
<!--                                                                     / 25
   Your job is to parse recipe.xml and display the contents as shown in the
   sample_output file.

   Some of code is already done for you - you should not have to change any 
   existing code unless you want to. You do *NOT* need to load the data into a 
   data structure - just display it properly on the screen as the parser 
   encounters it.                         

   Everything you need is in /Solutions/lab07/parser.php

   http://www.cs.csub.edu/~donna/cs350/Solutions/lab07/parser.php.txt

   If you want to display something from the command line and \n to insert 
   a line feed:
           printf("Recipe No: %d<BR/>\n",$n_items);
-->
<title>CS 350 Exam 2 PHP</title>
<body>
<h3>Name: samantha spade</h3>
<h3>Recipe Book XML Parser</h3>

<?php
   parse('recipe.xml');

function parse($filename)
{
     global $n_items;
     $n_items = 0;
      
     $xml_parser = xml_parser_create();
     
     // set handler for start and end tags   
     xml_set_element_handler($xml_parser, "XML_startElement","XML_endElement");

     // set handler for character data between tags
     xml_set_character_data_handler($xml_parser, "XML_data");

     if( !($fp = fopen($filename, 'r')) ) {
            die("could not open XML input");
     }

     // read 4096 bytes at a time
     while($data = fread($fp, 4096))
     {
        // parse the file
        if ( !xml_parse ( $xml_parser, $data, feof($fp) ) )
        {
          die(sprintf("XML error: %s at line %d",
          xml_error_string(xml_get_error_code($xml_parser)),
          xml_get_current_line_number($xml_parser)));
        }
     } 
     xml_parser_free($xml_parser);
}
//----------------------------------------------------------------------------
function XML_startElement($parser, $name, $attrs = '')
{
     global $n_items;

     switch($name)
     { 
        case 'RECIPEBOOK':


           break;

        case 'RECIPE':
           foreach($attrs as $key => $value)
           {  
              printf('%s: %s ',$key,$value);
           }
           printf("<BR/>\n");
           break;



    }
} 
//----------------------------------------------------------------------------
// function to handle the element's character data
function XML_data($parser, $data)
{
   $char_data = trim($data);
   if($char_data) 
        printf($char_data);
}
//----------------------------------------------------------------------------
function footer() {


}
//----------------------------------------------------------------------------
function XML_endElement($parser, $name) 
{ 
   printf("<BR/>\n");
}

//----------------------------------------------------------------------------

function title()
{
   global $n_items;
   $td = substr(date('r'),0,16);
   printf("<H3>RECIPE BOOK</H3>Date: %s<p>",$td);
   printf("\n<BR>");
}
?>
