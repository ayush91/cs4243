$(document).ready(function() { 
  $('div[data-role=page]').live('pageshow',function() {
    var socket = io.connect();
    var selection = "";

    socket.on('connect', function() {
      console.log('connected');
      socket.emit('pageID');
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

    $('#salads').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Potato Salad');
      $('.list2 a').html('Cajun Rice Salad');
      $('.list3 a').html('Corn and Red Pepper Salad');
      $('.list4 a').html('Shrimp and Roasted Red Potato Salad');
      $('.list5 a').html('Cajun Coleslaw');
      $('.list6 a').html('Blackened Chicken Salad');
      socket.emit('message', {screen: 'option', status: 'salads'});
    });

    $('#desserts').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Pralines');
      $('.list2 a').html('Baked Apples with Bourbon Pecan Sauce');
      $('.list3 a').html('Bread Pudding');
      $('.list4 a').html('Crepes Suzette');
      $('.list5 a').html('King Cake');
      $('.list6 a').html('Beignets');
      socket.emit('message', {screen: 'option', status: 'desserts'});
      
    });

    $('#entrees').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Red Beans and Rice');
      $('.list2 a').html('Jambalaya');
      $('.list3 a').html('Blackened Fish');
      $('.list4 a').html('Cajun Beer Can Chicken');
      $('.list5 a').html('Hog Roasts');
      $('.list6 a').html('Boiled Crawfish');
      socket.emit('message', {screen: 'option', status: 'entrees'});     
    });

    $('#drinks').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Hurricane');
      $('.list2 a').html('Zatarains Root Beer');
      $('.list3 a').html('Mint Julep');
      $('.list4 a').html('Cafe Brulot');
      $('.list5 a').html('The Vieux Carre');
      $('.list6 a').html('The St. Charles');
      socket.emit('message', {screen: 'option', status: 'drinks'});     
    });

    $('#soups').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Seafood Gumbo');
      $('.list2 a').html('Crawfish Etouffee');
      $('.list3 a').html('Alligator and Snapping Turtle Sauce Picquante');
      $('.list4 a').html('Cajun Bouillabaisse');
      $('.list5 a').html('Corn Maque Choux');
      $('.list6 a').html('Crawfish Bisque');
      socket.emit('message', {screen: 'option', status: 'soups'});     
    });

    $('#sides').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Baked Potato with Crawfish Etouffee');
      $('.list2 a').html('Cajun Fries');
      $('.list3 a').html('Cajun Onion Rings');
      $('.list4 a').html('Shrimp and Roasted Red Potato Salad');
      $('.list5 a').html('Stuff');
      $('.list6 a').html('Crawfish Bisque');
      socket.emit('message', {screen: 'option', status: 'sides'}); 
    });

    $('#appetizers').on('click', function() {
      $('#stuff').trigger('expand');
      $('.list1 a').html('Choupique Balls');
      $('.list2 a').html('Boudin and Boudin Balls');
      $('.list3 a').html('Stuffed Mushrooms');
      $('.list4 a').html('Shrimp and Roasted Red Potato Salad');
      $('.list5 a').html('Cajun Coleslaw');
      $('.list6 a').html('Blackened Chicken Salad');
      socket.emit('message', {screen: 'option', status: 'appetizers'});      
    });

    $('#home').on('click', function() {
      socket.emit('message', {screen: 'menu', status: 'off'});
    });

    $("#stuff ul li").on('click', function() {
      socket.emit('message', {screen: 'selection', status: this.id});
    });
  });
});
