var express = require('express');
var app = express();
var server = require('http').createServer(app);
var io = require('socket.io').listen(server);
var port = 8080;
var clients = {};

server.listen(port);

app.use(express.bodyParser());
app.use('/', express.static(__dirname + '/'));
app.use('/scripts', express.static(__dirname + '/scripts'));
app.use('/css', express.static(__dirname + '/css'));
app.use('/images', express.static(__dirname + '/images'));
app.use('/pages', express.static(__dirname + '/pages'));
app.use('/nutrition', express.static(__dirname + '/nutrition'));
app.use('/recipes', express.static(__dirname + '/recipes'));
app.use('/history', express.static(__dirname + '/history'));


io.enable('browser client minification');
io.enable('browser client etag');
io.enable('browser client gzip');
io.set('log level', 1);

io.set('transports', ['websocket', 'flashsocket', 'htmlfile', 'xhr-polling', 'jsonp-polling']);

io.on('connection', function(client) {
  client.on('pageID', function(data) {
    if (data == 'page1') {
      console.log('Page 1 has connected.');
      //clients['page1'] = client.id;
      //console.log(clients);
    } else if (data == 'page2') {
      console.log('Page 2 has connected.');
      //clients['page2'] = client.id;
      //console.log(clients);
    } else if (data == 'page3') {
      console.log('Page 3 has connected.');
      //clients['page3'] = client.id;
      //console.log(clients);
    } else if (data == 'page4') {
      console.log('Page 4 has connected.');
      //clients['page4'] = client.id;
      //console.log(clients);
    } else if (data == 'page5') {
      console.log('Page 5 has connected.');
      //clients['page5'] = client.id;
      //console.log(clients);
    } else if (data == 'page6') {
      console.log('Page 6 has connected.');
      //clients['page6'] = client.id;
      //console.log(clients);
    } else if (data == 'mobile1') {
      console.log('Mobile 1 has connected.');
      //clients['mobile1'] = client.id;
      //console.log(clients);
    } else if (data == 'mobile2') {
      console.log('Mobile 2 has connected.');
      //clients['mobile2'] = client.id;
      //console.log(clients);
    } else {
      console.log(client.id, 'has connected.');
      //clients[client.id] = client.id;
      //console.log(clients);
    }
  });

  client.on('message', function(data) {
    console.log('Client sent message', data.screen, data.status);
    client.broadcast.emit(data.screen, data.status);
  });

  client.on('disconnect', function(client) {
    console.log('Client has disconnected');
  });
});
