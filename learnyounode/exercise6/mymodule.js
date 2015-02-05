// MAKE IT MODULAR

var fs = require('fs');
var path = require('path');


module.exports = function (dir,ext,cb)
{
  fs.readdir(dir, function callback(err, contents) {
  if (err)
    return cb(err);
    
  var arr = [];
  contents.forEach(function(file) {
    if (path.extname(file) == '.'+ext){ 
      arr.push(file);
    }
  })
  cb(null,arr);
});

}

