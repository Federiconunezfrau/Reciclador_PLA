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
      Estado del calentador: <span id="STATE">NA</span><br>
      Temperatura: <span id="TEMP">NA</span><br>
      Set-point: <span id="SP">NA</span><br>
      Extrusion: <span id="EX">NA</span>
    </div>
  </div>
  <div class="column" id="controls">
    <h3 style="text-align:center;">Controles</h3>
    <div class="row">
      <div class="column" style="text-align:center;">
        Ajuste Set-Point : <span id="NewSP">185</span>
      </div>
    <div class="column" style="text-align:center;">
        <button type="button" onclick="updateSP(1)">+</button>
        <button type="button" onclick="updateSP(0)">-</button>
        <button type="button" id="send_sp_btn" onclick="send_sp()">Enviar</button>
      </div>
    </div>
    <br>
    <div class="row">
      <div class="column" style="text-align:center;">
        <button type="button" id="heat_btn" onclick="heat()" disabled>Cargando...</button>
      </div>
    <div class="column" style="text-align:center;">
      <button type="button" id="extrude_btn" onclick="extrude()">Extruir</button>
      <button type="button" id="stop_btn" onclick="stopextrude()">Detener</button>
      <br><br>
      <button type="button" id="change_net_btn" onclick="change_net()">Cambiar red</button>
      </div>
    </div>

  </div>
</div>

<script>
function updateSP (data) {
  var sp = document.getElementById("NewSP");
  var sp_value = parseInt(sp.innerHTML); 
  if (data == 1){
    if (sp_value < 210) {
      sp.innerHTML = sp_value + 1;
    }
  }
  else if (data == 0) {
    if (sp_value > 160) {
      sp.innerHTML = sp_value - 1;
    }
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
  xhttp.open("GET", "sp?value="+sp, true);
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
        document.getElementById("EX").innerHTML = (response.split(',')[3]);
        
        var ST = document.getElementById("STATE");
        if (ST.innerHTML == "ON") {
          document.getElementById("heat_btn").disabled = false;
          document.getElementById("heat_btn").innerHTML = "Enfriar";
        }
        else if (ST.innerHTML == "OFF") {
          document.getElementById("heat_btn").disabled = false;
          document.getElementById("heat_btn").innerHTML = "Calentar";
        }
        else if (ST.innerHTML == "NA") {
          document.getElementById("heat_btn").disabled = true;
          document.getElementById("heat_btn").innerHTML = "Cargando...";
        }
      }
    }
  };
  xhttp.open("GET", "read", true);
  xhttp.send(); 
}

function heat() {
  var st_btn = document.getElementById("heat_btn").innerHTML;
  var value = "0";
  if (st_btn == "Calentar") {
    value = "1";
  }
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      console.log("ENVIADO:" + this.responseText);
    }
  };
  xhttp.open("GET", "heat?value="+value, true);
  xhttp.send();
}

function extrude() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      console.log("ENVIADO:" + this.responseText);
    }
  };
  xhttp.open("GET", "extrude?value=1", true);
  xhttp.send();
}

function stopextrude() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      console.log("ENVIADO:" + this.responseText);
    }
  };
  xhttp.open("GET", "extrude?value=0", true);
  xhttp.send();
}

function change_net() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      console.log("ENVIADO:" + this.responseText);
    }
  };
  xhttp.open("GET", "disconnect?value=1", true);
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
