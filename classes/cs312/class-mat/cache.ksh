#
#
# this runs the cache.c program with the following line_offset values
# and makes a table:
#
#		 127		 128
#		 251	 	 256
#		 509		 512
#		1021		1024
#		2039		2048
#		4093		4096	(pagesize on PowerBookG4)
#		8191		8192	(most common pagesize except 80x86)
#
TMPFILE=tmpfile
POWEROFTWO=128
#
# for LINEOFF in " 127" " 128" " 251" " 256" " 509" " 512" "1021" "1024" \
# 		"2039" "2048" "4093" "4096" 
# "8191" "8192"
#
for LINEOFF in " 127" " 251" " 509"  "1021" "2039" "4093"  
#
do
	echo "$LINEOFF" | ./cache > $TMPFILE
	VALUE1=`cat $TMPFILE| grep "Bandwidth" | awk '{ print $4 " " $5 }' `
#	echo "results:    $LINEOFF: $VALUE" > 
#
	echo $POWEROFTWO | ./cache > $TMPFILE
	VALUE2=`cat $TMPFILE | grep "Bandwidth" | awk '{ print $4 " " $5 }' `
	echo "results:   $LINEOFF: $VALUE1        $POWEROFTWO: $VALUE2"
#
# NO spaces in the following
	let POWEROFTWO=POWEROFTWO*2
done
#
# clean up
rm -f $TMPFILE

