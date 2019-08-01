var fs = require('fs');

var content = fs.readFileSync('./input.txt', 'utf8');
var lines = content.split('\n');

var numCases = parseInt(lines.shift());
var currentCase;
var fileOut = [];

for (currentCase = 0; currentCase < numCases; currentCase++) {
  var data = lines.shift();
  var splitData = data.split(' ');
  var distance = parseInt(splitData[0]);
  var numHorses = parseInt(splitData[1]);
  var index, horseIndex;
  var horseData = [];
  var maxTime = 0;
  var maxSpeed

  for (index = 0; index < numHorses; index++) {
    const data = lines.shift();
    const start = data.split(' ')[0];
    const speed = data.split(' ')[1];

    horseData.push({ start, speed });
  }
  
  for (horseIndex = 0; horseIndex < horseData.length; horseIndex++) {
    const currentHorse = horseData[horseIndex];
    const time = (distance - currentHorse.start) / currentHorse.speed;
    
    if (time > maxTime) {
      maxTime = time;
    }
  }
  
  maxSpeed = distance / maxTime;

  console.log('Case #' + (currentCase + 1) + ': ' + maxSpeed)
  fileOut.push('Case #' + (currentCase + 1) + ': ' + maxSpeed);
}

fs.writeFile('out.txt', fileOut.join('\n'), function(err) {
  if(err) {
    return console.log(err);
  }
});
