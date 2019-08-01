var fs = require('fs');
var content = fs.readFileSync('C:\/Users\/irobot\/Documents\/GitHub\/codingContest\/help\/small.txt', 'utf8');
var lines = content.split('\r\n');

var numCases = parseInt(lines.shift());		// number - 5
var name = lines.shift();					// string - sridhar
var aryNumber = lines.shift().split(' ');	// array of number string - [ '10', '11', '12' ]
var aryString = lines.shift().split(' ');	// array of string - [ 'moni', 'janai', 'nandi', 'jay' ]



/*
5
sridhar
10 11 12
moni janai nandi jay
*/