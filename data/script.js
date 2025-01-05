// Get current sensor readings when the page loads  
window.addEventListener('load', getReadings);

// Create Temperature Gauge
var gaugeTemp = new LinearGauge({
  renderTo: 'gauge-temperature',
  width: 120,
  height: 400,
  units: "Temperature °F",
  minValue: 20,
  maxValue: 50,
  colorValueBoxRect: "#ccc",
  colorValueBoxRectEnd: "#ccc",
  colorValueBoxBackground: "#f1fbfc",
  valueDec: 2,
  valueInt: 2,
  //startAngle: 90,
  //ticksAngle: 180,
  tickSide: "right",
  numberSide: "right",
  needleSide: "left",
  majorTicks: [
      "20",
      "25",
      "30",
      "35",
      "40",
      "45",
      "50"
  ],
  minorTicks: 4,
  strokeTicks: true,
  highlights: [
      {
          "from": 40,
          "to": 50,
          "color": "rgba(200, 50, 50, .75)"
      },
      {
        "from": 20,
        "to": 32,
        "color": "rgba(0, 0, 200, .75)"
    }
  ],
  colorPlate: "#222",
  colorBarProgress: "#CC2936",
  colorBarProgressEnd: "#049faa",
  colorNumbers: "#ccc",
  borderShadowWidth: 0,
  borders: true,
  borderInnerWidth: 0,
  borderMiddleWidth: 0,
  borderOuterWidth: 1,
  borderRadius: 9,
  colorBorderOuter: "#ccc",
  colorBorderOuterEnd: "#ccc",  
  barStrokeWidth: "5",
  needleType: "arrow",
  //needleWidth: 2,
  needleCircleSize: 7,
  needleCircleOuter: true,
  needleCircleInner: false,
  animationDuration: 1500,
  animationRule: "linear",
  barWidth: 20,
}).draw();
 
  
// Create Keg1 Gauge
var gaugeKeg1 = new RadialGauge({
  renderTo: 'gauge-keg1',
  width: 210,
  height: 210,
  units: "Fluid Oz",
  minValue: 0,
  maxValue: 660,
  colorValueBoxRect: "#ccc",
  colorValueBoxRectEnd: "#ccc",
  colorValueBoxBackground: "#f1fbfc",
  valueInt: 2,
  valueBox: true,
  majorTicks: [
      "0",
      "110",
      "220",
      "330",
      "440",
      "550",
      "660"

  ],
  minorTicks: 4,
  strokeTicks: true,
  highlights: [
      {
          "from": 0,
          "to": 50,
          "color": "#C83232"
      }
  ],
  colorPlate: "#222",
  borderShadowWidth: 2,
  borders: true,
  borderInnerWidth: 0,
  borderMiddleWidth: 0,
  borderOuterWidth: 2,
  colorBorderOuter: "#ccc",
  colorBorderOuterEnd: "#ccc",  
  colorMajorTicks: "#f5f5f5",
  colorMinorTicks: "#ddd",
  colorNumbers: "#ccc",
  needle: true,
  needleType: "arrow",
  /*colorNeedle: "#007F80",
  colorNeedleEnd: "#007F80",*/
  needleWidth: 2,
  needleCircleSize: 7,
  colorNeedleShadowDown: "#333",
  colorNeedleCircleOuter: "#333",
  colorNeedleCircleOuterEnd: "#111",
  colorNeedleCircleInner: "#111",
  colorNeedleCircleInnerEnd: "#222",  needleCircleOuter: true,
  needleCircleInner: false,
  barWidth:5,
  barShadow:2,
  colorBar:"rgba(57, 57, 96, 0.75)",  
  colorBarProgress:"rgba(50,50,200,.75)",
  animationDuration: 1500,
  animationRule: "linear"
}).draw();



// Create Keg2 Gauge
var gaugeKeg2 = new RadialGauge({
  renderTo: 'gauge-keg2',
  width: 210,
  height: 210,
  units: "Fluid Oz",
  minValue: 0,
  maxValue: 660,
  colorValueBoxRect: "#049faa",
  colorValueBoxRectEnd: "#049faa",
  colorValueBoxBackground: "#f1fbfc",
  valueInt: 2,
  valueBox: true,
  majorTicks: [
      "0",
      "110",
      "220",
      "330",
      "440",
      "550",
      "660"

  ],
  minorTicks: 4,
  strokeTicks: true,
  highlights: [
      {
          "from": 0,
          "to": 50,
          "color": "#C83232"
      }
  ],
  colorPlate: "#222",
  borderShadowWidth: 2,
  borders: true,
  borderInnerWidth: 0,
  borderMiddleWidth: 0,
  borderOuterWidth: 2,
  colorBorderOuter: "#ccc",
  colorBorderOuterEnd: "#ccc",  
  colorMajorTicks: "#f5f5f5",
  colorMinorTicks: "#ddd",
  colorNumbers: "#ccc",
  needle: true,
  needleType: "arrow",
  /*colorNeedle: "#007F80",
  colorNeedleEnd: "#007F80",*/
  needleWidth: 2,
  needleCircleSize: 7,
  colorNeedleShadowDown: "#333",
  colorNeedleCircleOuter: "#333",
  colorNeedleCircleOuterEnd: "#111",
  colorNeedleCircleInner: "#111",
  colorNeedleCircleInnerEnd: "#222",  needleCircleOuter: true,
  needleCircleInner: false,
  barWidth:5,
  barShadow:2,
  colorBar:"rgba(57, 57, 96, 0.75)",  
  colorBarProgress:"rgba(50,50,200,.75)",
  animationDuration: 1500,
  animationRule: "linear"
}).draw();



// Create Keg3 Gauge
var gaugeKeg3 = new RadialGauge({
  renderTo: 'gauge-keg3',
  width: 210,
  height: 210,
  units: "Fluid Oz",
  minValue: 0,
  maxValue: 660,
  colorValueBoxRect: "#049faa",
  colorValueBoxRectEnd: "#049faa",
  colorValueBoxBackground: "#f1fbfc",
  valueInt: 2,
  valueBox: true,
  majorTicks: [
      "0",
      "110",
      "220",
      "330",
      "440",
      "550",
      "660"

  ],
  minorTicks: 4,
  strokeTicks: true,
  highlights: [
      {
          "from": 0,
          "to": 50,
          "color": "#C83232"
      }
  ],
  colorPlate: "#222",
  borderShadowWidth: 2,
  borders: true,
  borderInnerWidth: 0,
  borderMiddleWidth: 0,
  borderOuterWidth: 2,
  colorBorderOuter: "#ccc",
  colorBorderOuterEnd: "#ccc",  
  colorMajorTicks: "#f5f5f5",
  colorMinorTicks: "#ddd",
  colorNumbers: "#ccc",
  needle: true,
  needleType: "arrow",
  /*colorNeedle: "#007F80",
  colorNeedleEnd: "#007F80",*/
  needleWidth: 2,
  needleCircleSize: 7,
  colorNeedleShadowDown: "#333",
  colorNeedleCircleOuter: "#333",
  colorNeedleCircleOuterEnd: "#111",
  colorNeedleCircleInner: "#111",
  colorNeedleCircleInnerEnd: "#222",  needleCircleOuter: true,
  needleCircleInner: false,
  barWidth:5,
  barShadow:2,
  colorBar:"rgba(57, 57, 96, 0.75)",  
  colorBarProgress:"rgba(50,50,200,.75)",
  animationDuration: 1500,
  animationRule: "linear"
}).draw();



// Create Keg4 Gauge
var gaugeKeg4 = new RadialGauge({
  renderTo: 'gauge-keg4',
  width: 210,
  height: 210,
  units: "Fluid Oz",
  minValue: 0,
  maxValue: 660,
  colorValueBoxRect: "#049faa",
  colorValueBoxRectEnd: "#049faa",
  colorValueBoxBackground: "#f1fbfc",
  valueInt: 2,
  valueBox: true,
  majorTicks: [
      "0",
      "110",
      "220",
      "330",
      "440",
      "550",
      "660"

  ],
  minorTicks: 4,
  strokeTicks: true,
  highlights: [
      {
          "from": 0,
          "to": 50,
          "color": "#C83232"
      }
  ],
  colorPlate: "#222",
  borderShadowWidth: 2,
  borders: true,
  borderInnerWidth: 0,
  borderMiddleWidth: 0,
  borderOuterWidth: 2,
  colorBorderOuter: "#ccc",
  colorBorderOuterEnd: "#ccc",  
  colorMajorTicks: "#f5f5f5",
  colorMinorTicks: "#ddd",
  colorNumbers: "#ccc",
  needle: true,
  needleType: "arrow",
  /*colorNeedle: "#007F80",
  colorNeedleEnd: "#007F80",*/
  needleWidth: 2,
  needleCircleSize: 7,
  colorNeedleShadowDown: "#333",
  colorNeedleCircleOuter: "#333",
  colorNeedleCircleOuterEnd: "#111",
  colorNeedleCircleInner: "#111",
  colorNeedleCircleInnerEnd: "#222",  needleCircleOuter: true,
  needleCircleInner: false,
  barWidth:5,
  barShadow:2,
  colorBar:"rgba(57, 57, 96, 0.75)",  
  colorBarProgress:"rgba(50,50,200,.75)",
  animationDuration: 1500,
  animationRule: "linear"
}).draw();



// Function to get current readings on the webpage when it loads for the first time
function getReadings(){
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var myObj = JSON.parse(this.responseText);
      console.log(myObj);
      var temp = myObj.temperature;
      gaugeTemp.value = temp;

      gaugeKeg1.value = myObj.keg1Ounces;
      gaugeKeg2.value = myObj.keg2Ounces;
      gaugeKeg3.value = myObj.keg3Ounces;
      gaugeKeg4.value = myObj.keg4Ounces;

      
    document.getElementsByName("Keg1BeerName")[0].value = myObj.keg1Contentname;
    document.getElementsByName("Keg1Weight")[0].value = myObj.keg1Weight + " lbs";
    document.getElementsByName("Keg1Oz16")[0].value = (myObj.keg1Ounces/16).toFixed(1);      
    document.getElementsByName("Keg1Oz12")[0].value = (myObj.keg1Ounces/12).toFixed(1);      

    document.getElementsByName("Keg2BeerName")[0].value = myObj.keg2Contentname;
    document.getElementsByName("Keg2Weight")[0].value = myObj.keg2Weight + " lbs";
    document.getElementsByName("Keg2Oz16")[0].value = (myObj.keg2Ounces/16).toFixed(1);      
    document.getElementsByName("Keg2Oz12")[0].value = (myObj.keg2Ounces/12).toFixed(1);      

    document.getElementsByName("Keg3BeerName")[0].value = myObj.keg3Contentname;
    document.getElementsByName("Keg3Weight")[0].value = myObj.keg3Weight + " lbs";
    document.getElementsByName("Keg3Oz16")[0].value = (myObj.keg3Ounces/16).toFixed(1);      
    document.getElementsByName("Keg3Oz12")[0].value = (myObj.keg3Ounces/12).toFixed(1);      

    document.getElementsByName("Keg4BeerName")[0].value = myObj.keg4Contentname;
    document.getElementsByName("Keg4Weight")[0].value = myObj.keg4Weight + " lbs";
    document.getElementsByName("Keg4Oz16")[0].value = (myObj.keg4Ounces/16).toFixed(1);      
    document.getElementsByName("Keg4Oz12")[0].value = (myObj.keg4Ounces/12).toFixed(1); 

      console.log("hehe");
      console.log(document.getElementsByName("Keg1BeerName")[0].value);
    }
  }; 
  xhr.open("GET", "/readings", true);
  xhr.send();
}

if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('submit', function(e) {
    console.log("Something Submitted");
  }, false);
  
  source.addEventListener('open', function(e) {
    console.log("Events Connected");
  }, false);

  source.addEventListener('error', function(e) {
    if (e.target.readyState != EventSource.OPEN) {
      console.log("Events Disconnected");
    }
  }, false);
  
  source.addEventListener('message', function(e) {
    console.log("message", e.data);
  }, false);
  
  source.addEventListener('new_readings', function(e) {
    console.log("new_readings", e.data);
    var myObj = JSON.parse(e.data);
    console.log(myObj);
    gaugeTemp.value = myObj.temperature;
    gaugeKeg1.value = myObj.keg1Ounces;
    gaugeKeg2.value = myObj.keg2Ounces;
    gaugeKeg3.value = myObj.keg3Ounces;
    gaugeKeg4.value = myObj.keg4Ounces;


    /*document.getElementsByName("Keg1BeerName")[0].value = myObj.keg1Contentname;*/
    document.getElementsByName("Keg1Weight")[0].value = myObj.keg1Weight + " lbs";
    document.getElementsByName("Keg1Oz16")[0].value = (myObj.keg1Ounces/16).toFixed(1);      
    document.getElementsByName("Keg1Oz12")[0].value = (myObj.keg1Ounces/12).toFixed(1);      

    /*document.getElementsByName("Keg2BeerName")[0].value = myObj.keg2Contentname;*/
    document.getElementsByName("Keg2Weight")[0].value = myObj.keg2Weight + " lbs";
    document.getElementsByName("Keg2Oz16")[0].value = (myObj.keg2Ounces/16).toFixed(1);      
    document.getElementsByName("Keg2Oz12")[0].value = (myObj.keg2Ounces/12).toFixed(1);      

    /*document.getElementsByName("Keg3BeerName")[0].value = myObj.keg3Contentname;*/
    document.getElementsByName("Keg3Weight")[0].value = myObj.keg3Weight + " lbs";
    document.getElementsByName("Keg3Oz16")[0].value = (myObj.keg3Ounces/16).toFixed(1);      
    document.getElementsByName("Keg3Oz12")[0].value = (myObj.keg3Ounces/12).toFixed(1);      

    /*document.getElementsByName("Keg4BeerName")[0].value = myObj.keg4Contentname;*/
    document.getElementsByName("Keg4Weight")[0].value = myObj.keg4Weight + " lbs";
    document.getElementsByName("Keg4Oz16")[0].value = (myObj.keg4Ounces/16).toFixed(1);      
    document.getElementsByName("Keg4Oz12")[0].value = (myObj.keg4Ounces/12).toFixed(1);      

/*
    var Keg4Ounces    = myObj.keg4Ounces;
    var Keg4Weight    = myObj.keg4Weight;
    var Keg4Beername  = myObj.keg4Contentname;

    console.log(Keg1Beername);
*/
/*
    var pints = myObj.keg1Ounces/16;
    var cans = myObj.keg1Ounces/12;
    document.getElementsByName("Keg1Oz16")[0].value = pints.toFixed(1);      
    document.getElementsByName("Keg1Oz12")[0].value = cans.toFixed(1); 
*/         

  }, false);

}



/**
 * Helper function for POSTing data as JSON with fetch.
 *
 * @param {Object} options
 * @param {string} options.url - URL to POST data to
 * @param {FormData} options.formData - `FormData` instance
 * @return {Object} - Response body from URL that was POSTed to
 */
async function postFormDataAsJson({ url, formData }) {
	const plainFormData = Object.fromEntries(formData.entries());
	const formDataJsonString = JSON.stringify(plainFormData);

  console.log(formDataJsonString);

	const fetchOptions = {
		method: "POST",
		headers: {
			"Content-Type": "application/json",
			Accept: "application/json",
		},
		body: formDataJsonString,
	};

	const response = await fetch(url, fetchOptions);

	if (!response.ok) {
		const errorMessage = await response.text();
		throw new Error(errorMessage);
	}

	return response.json();
}

/**
 * Event handler for a form submit event.
 *
 * @see https://developer.mozilla.org/en-US/docs/Web/API/HTMLFormElement/submit_event
 *
 * @param {SubmitEvent} event
 */
async function handleFormSubmit(eventt) {
	eventt.preventDefault();

	const form = eventt.currentTarget;
	const url = "http://mykeezer.local/setkeg";

  console.log("Sending sampleForm textbox info as JSON");

	try {
		const formData = new FormData(form);
		const responseData = await postFormDataAsJson({ url, formData });

		console.log({ responseData });
	} catch (error) {
		console.error(error);
	}


}

const exampleForm = document.querySelector("#sampleForm");
exampleForm.addEventListener("submit", handleFormSubmit);

const exampleForm2 = document.querySelector("#kegForm2");
exampleForm2.addEventListener("submit", handleFormSubmit);

const exampleForm3 = document.querySelector("#kegForm3");
exampleForm3.addEventListener("submit", handleFormSubmit);

const exampleForm4 = document.querySelector("#kegForm4");
exampleForm4.addEventListener("submit", handleFormSubmit);