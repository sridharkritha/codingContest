// Google Code Jam Qualification Round 2018
// Solution in Javascript / node.js
// By Sridhar

var readline = require('readline');

function solveCase(a, x) 
{
	// var a =  [1,2,3,4,5,9,6]; // [8, 9, 7]; // [5, 6, 6, 4, 3];
	var t = 0;
	var pass = true, recurr = false;
	var min = 0;

	while (pass)
	{
		pass = false;

		for(var i = 0; i < a.length - 2; ++i)
		{
			if(parseInt(a[i]) > parseInt(a[i+2]))
			{
				pass = true;

				t = a[i];
				a[i] = a[i+2];
				a[i+2] = t;
			}
/*
			if(i + 2 === a.length - 1)
			{
				if(parseInt(a[a.length - 1]) < parseInt(a[a.length - 2]))
				{
					console.log('Case #' + x + ': ' + (i + 1));
					// console.log(i + 1);
					pass = false;
					recurr = true;
					break;
				}
			}
*/
		}
	}

	min = parseInt(a[0]);

	for(var i = 1; i < a.length; ++i)
	{
		if(min < parseInt(a[i]))
		{
			min = parseInt(a[i]);
		}
		else
		{
			console.log('Case #' + x + ': ' + (i - 1));
			// console.log(i - 1);
			recurr = true;
			break;
		}
	}

	if(!pass && !recurr)
	{
		console.log('Case #' + x + ': ' + "OK");
		// console.log("OK");
	}
}

var rl = readline.createInterface({
	input: require('fs').createReadStream('C:\/Users\/irobot\/Documents\/GitHub\/codingContest\/help\/small.txt'),
	// input: process.stdin,
	terminal: false
	// input: require('fs').createReadStream('small.txt')
});

var x = -1;
var tc = 0;
rl.on('line', function (line) {
	x++;

	if (x > 0 && x % 2 === 0) 
	// if (x > 0)
	{
		var temp = line.split(' ');
		// var res = solveCase(parseInt(temp[0]), parseInt(temp[1]), parseInt(temp[2]));
		// console.log('Case #' + x + ': ' + res);

		solveCase(temp, ++tc);

	}
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
