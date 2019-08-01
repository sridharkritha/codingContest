// Google Code Jam Qualification Round 2018
// Solution in Javascript / node.js
// By Sridhar

var readline = require('readline');
var rl = readline.createInterface({
	input: require('fs').createReadStream('C:\/Users\/irobot\/Documents\/GitHub\/codingContest\/help\/small.txt'),
	// input: process.stdin,
	terminal: false
});

function solveCase(a, x)
{
	console.log('---------------------------------------');
	console.log(a); // parseInt(a[0]);
}

var x = -1;

rl.on('line', function (line) {
	x++;

	var temp = line.split(' ');
	solveCase(temp, x);
});

/*
2
5
5 6 8 4 3
3
8 9 7

4
2 2 2
2 1 3
4 4 1
3 2 3

*/
