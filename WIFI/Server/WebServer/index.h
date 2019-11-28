const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body style="background-color: #e6ffe6;">
<div>
  <h1 style="text-align:center;">Reciclador de PLA</h1>
</div>

<div class="row">
  <div class="column">
  	<h3 style="text-align:center;">Estado actual</h3>
    <div>
      Estado actual: <span id="STATE">LOADING</span><br>
      Temperatura: <span id="TEMP">NA</span><br>
      Set-point: <span id="SP">NA</span>
    </div>
  </div>
  <div class="column" id="controls">
  	<h3 style="text-align:center;">Controles</h3>
    <div class="row">
      <div class="column" style="text-align:center;">
        Ajuste Set-Point : <span id="NewSP">200</span>
      </div>
	  <div class="column" style="text-align:center;">
      	<button type="button" onclick="updateSP(1)">+</button>
      	<button type="button" onclick="updateSP(0)">-</button>
      </div>
    </div>
    <br>
    <div style="text-align:center;">
    	<button type="button" id="send_sp_btn" onclick="send_sp()">Send</button>
    </div>
  </div>
</div>
<br><br>
<div id="power" style="text-align:center;">
	<button type="button" id="start_btn" onclick="start()" disabled>Loading</button>
</div>

<script>
function updateSP (data) {
  var sp = document.getElementById("NewSP");
  var sp_value = parseInt(sp.innerHTML); 
  if (data == 1){
    if (sp_value < 230) {
      sp.innerHTML = sp_value + 1;
    }
  }
  else if (data == 0) {
    if (sp_value > 180) {
      sp.innerHTML = sp_value - 1;
    }
  }
  sp_value = parseInt(sp.innerHTML);
  if (sp_value == parseInt(actual_sp.innerHTML)) {
    sp.setAttribute("style", "color:black;");
    ok_btn.disabled = true;
  }
  else {
    sp.setAttribute("style", "color:red;");
    ok_btn.disabled = false;
  }
}

function send_sp() {
  var sp = document.getElementById("NewSP").innerHTML;
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      console.log("ENVIADO:" + this.responseText);
    }
  };
  xhttp.open("GET", "send?value="+sp, true);
  xhttp.send();
}


setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 500); //500mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var response = this.responseText;
      if (response == "") {}
      else {
        document.getElementById("STATE").innerHTML = (response.split(',')[0]);
        document.getElementById("TEMP").innerHTML = (response.split(',')[1]);
        document.getElementById("SP").innerHTML = (response.split(',')[2]);
        var ST = document.getElementById("STATE");
        if (ST.innerHTML == "RUNNING") {
          document.getElementById("start_btn").disabled = false;
          document.getElementById("start_btn").innerHTML = "Stop";
        }
        else if (ST.innerHTML == "STOPPED") {
          document.getElementById("start_btn").disabled = false;
          document.getElementById("start_btn").innerHTML = "Start";
        }
        else if (ST.innerHTML == "LOADING") {
          document.getElementById("start_btn").disabled = true;
          document.getElementById("start_btn").innerHTML = "Loading";
        }
      }
    }
  };
  xhttp.open("GET", "read", true);
  xhttp.send(); 
}

function start() {
  var st_btn = document.getElementById("start_btn").innerHTML;
  var value = "0"
  if (st_btn == "Start") {
    value = "1";
  }
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      console.log("ENVIADO:" + this.responseText);
    }
  };
  xhttp.open("GET", "start?value="+value, true);
  xhttp.send();
}

</script>
<style>
.column {
  float: left;
  width: 50%;
}

/* Clear floats after the columns */
.row:after {
  content: "";
  display: table;
  clear: both;
}

.btn {
  background-color: #008CBA;/* Green */
  border-radius: 4px;
  color: white;
  padding: 5px 10px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 10px;
}

.btn:hover {
  box-shadow: 0 12px 16px 0 rgba(0,0,0,0.24), 0 17px 50px 0 rgba(0,0,0,0.19);
}



</style>
</body>
</html>
)=====";
