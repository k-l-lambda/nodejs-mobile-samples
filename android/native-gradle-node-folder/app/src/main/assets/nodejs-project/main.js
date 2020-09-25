var http = require('http');
//var leftPad = require('left-pad');
var fc = require('./function-call');
var versions_server = http.createServer( async (request, response) => {
	//response.end('Versions: ' + JSON.stringify(process.versions) + ' left-pad: ' + leftPad(42, 5, '0'));
	//response.end('FC: ' + fc.hello().toString());

	const t0 = Date.now();
	const result = await fc.say("hello.");
	response.end(`FC[${t0}]: ` + result);
});
versions_server.listen(3000);
console.log('The node project has started.');
