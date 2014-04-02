$(document).ready(function() {
  var socket = io.connect();
	var selItem = '';
	var tempItem = '';

  socket.on('connect', function() {
    console.log('connected');
    socket.emit('pageID', 'page1');
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

  // Initial stage of page
  $(function() {
    $('#menu').hide();
  });

  socket.on('menu', function(data) {
    console.log(data);
    if (data == 'on') {
      $('span').hide();
      $('#menu').show();
    } else if (data == 'off') {
      $('#menu').hide();
      $('span').show();
    } else {
      console.log('Error in Javascript');
    }
  });
  
  socket.on('option', function(data) {
		tempItem = data;
		console.log(tempItem);
		
		if (selItem != tempItem) {
			hiSel = '#' + tempItem;
			loSel = '#' + selItem;
			$(hiSel).css({'background-color': '#55ee44'});
			$(loSel).css({'background-color': '#555555'});
		} else {
			console.log('........');
		}
		
		selItem = tempItem;
					
					

  });
});
