$(document).ready(function() {
  var socket = io.connect();
  var selGroup;

  socket.on('connect', function() {
    console.log('connected');
    socket.emit('pageID', 'page4');
  });

  socket.on('disconnect', function() {
    console.log('disconnected');
  });

  socket.on('error', function(err) {
    if (err === 'handshake error') {
      console.log('handshake error', err);
    } else {
      console.log('io error', err);
    }
  });

  // Initial state of page
  $(function () {
    $('#content').html('<img src="../images/Hurricane.jpg">');
    $('#content').show();
  });

  socket.on('menu', function(data) {
    console.log(data);
    if (data == 'on') {
      $('#content img').remove();
      $('#content').html('<div id="header"><span><h1>Cuisine</h1></span></div>');
      $('#content img').hide();
    } else if (data == 'off') {
      $('#content h1').remove();
      $('#content').html('<img src="../images/Hurricane.jpg">');
      $('#content').show();
    } else {
      console.log('Error in Javascript');
    }
  });

  socket.on('option', function(data) {
    console.log(data);
    selGroup = data;
  });

  socket.on('selection', function(data) {
    var selItem = selGroup + data + 'Hist';
    console.log(selItem);
    $('#content h1').remove();
    $('#content').load('../pages/' + selItem + '.html #recipe');
    $('#content').show();
    selItem = '';
  });
});