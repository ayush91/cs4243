$(document).ready(function() {
  var socket = io.connect();
  var selGroup = '';
  var thumb;

  // var items = [];
  // var thumbnails = [];

  socket.on('connect', function() {
    console.log('connected');
    socket.emit('pageID', 'page5');
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
    $('#content').html('<img src="../images/Gumbo.jpg">');
    $('#content').show();
  });

  socket.on('option', function(data) {
    console.log(data);
    selGroup = data;
  });

  socket.on('selection', function(data) {
    console.log(data);
    var selItem = '';
    selItem = data;
    console.log(selItem);
    $.getJSON('../images/images.json', function(data) {
      $.each(data, function(idx, obj) {
        // console.log(idx);
        if (selGroup == idx) {
          console.log(obj);
          thumb = obj[selItem];
          console.log(obj[selItem]);
          $('#content').html('<img src="' + obj[selItem] + '">');
        }
      });
    });
  });

    
});
