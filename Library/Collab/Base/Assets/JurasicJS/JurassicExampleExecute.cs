using UnityEngine;
using System.Collections;
using Jurassic;
using Jurassic.Library;

public class JurassicExampleExecute : MonoBehaviour 
{	
	ScriptEngine engine;
	bool running = true;
	public string codeString = "";	
	public string floatingText = "";
	public GUISkin editorStyle;
	bool girar = false;
	int anguloFinal = 0;
	int posfinal;
	bool avanzar = false;
	float tiempoAvance = 0f;
	float velocidadAvance = 0f;

	void Awake()
	{
		// Create an instance of the Jurassic engine then expose some stuff to it.
		engine  = new ScriptEngine();
		
		// Arguments and returns of functions exposed to JavaScript must be of supported types.
		// Supported types are bool, int, double, string, Jurassic.Null, Jurassic.Undefined
		// and Jurassic.Library.ObjectInstance (or a derived type).
		// More info: http://jurassic.codeplex.com/wikipage?title=Supported%20types
		
		// Examples of exposing some static classes to JavaScript using Jurassic's "seamless .NET interop" feature.
		engine.EnableExposedClrTypes = true; // You must enable this in order to use interop feaure.
		// Then pass the names and types of the classes you want to expose to SetGlobalValue().
		engine.SetGlobalValue("Mathf", typeof(Mathf));
		engine.SetGlobalValue("Input", typeof(Input));
		engine.SetGlobalValue ("Time", typeof(Time));
			
		// Examples of exposing some .NET methods to JavaScript.
		// The generic System.Action delegate is used to define method signatures with no returns;
		engine.SetGlobalFunction("SetPos", new System.Action<double, double, double>(jsSetPos));
		engine.SetGlobalFunction("SetPosVec", new System.Action<jsVectorInstance>(jsSetPosVec));
		engine.SetGlobalFunction("SetText", new System.Action<string>(jsSetText));
		engine.SetGlobalFunction("AddForce", new System.Action<double, double, double>(jsAddForce));
		engine.SetGlobalFunction ("Girar", new System.Action<int> (jsGirar));
		engine.SetGlobalFunction ("Avanzar", new System.Action<double, int> (jsAvanzar));


		// Examples of exposing some .NET methods with return values to JavaScript.
		// The generic System.Func delegate is used to define method signatures with return types;
		engine.SetGlobalFunction("GetPos", new System.Func<jsVectorInstance>(jsGetPos));
		engine.SetGlobalFunction("GetX", new System.Func<double>(jsGetX));
		engine.SetGlobalFunction("GetY", new System.Func<double>(jsGetY));
		engine.SetGlobalFunction("GetZ", new System.Func<double>(jsGetZ));
		engine.SetGlobalFunction("GetText", new System.Func<string>(jsGetText));


		// Example of creating a static .NET class to expose to JavaScript
		engine.SetGlobalValue("Days", new jsDayIterator(engine));

		// Example of creating an instance class with a constructor in JavaScript
		engine.SetGlobalValue("Vector", new jsVectorConstructor(engine));

		engine.SetGlobalFunction("Print", new System.Action<string>(jsPrint));

	}
	
	
	#region JS Functions
	// This set of methods implment the functions we exposed to javaScript.
	
	// Implementation of the JS functions for get/setting position using seperate x, y and z
	// values as type double. (float is not a supported type in Jurassic)
	public double jsGetX() { return (double)transform.position.x; }
	public double jsGetY() { return (double)transform.position.y; }
	public double jsGetZ() { return (double)transform.position.z; }

	public  void jsGirar(int angle) {

		StartCoroutine (corutinaGirar (angle));

	}

	IEnumerator corutinaGirar (int angle){
		while (girar || avanzar) {
			yield return null;
		}
		girar = true;
		anguloFinal = (int) transform.rotation.eulerAngles.y + angle;
		float posinicial = transform.rotation.eulerAngles.y;
		if (anguloFinal > 360) {
			 anguloFinal -= 360;
		}
		else if (anguloFinal < 0) {
			anguloFinal += 360;
		}
		Debug.Log ("Angulo Final: " + anguloFinal);
		Debug.Log ("Girar " + angle + " grados");

		// Giro a derecha
		if (angle >= 0) {
		
			while ((transform.rotation.eulerAngles.y > anguloFinal) & (transform.rotation.eulerAngles.y >= posinicial)){
				transform.Rotate (0, 0.5f, 0, Space.World);
				yield return new WaitForSeconds (0.01f);
			}
			if (transform.rotation.eulerAngles.y < anguloFinal) {
				while (transform.rotation.eulerAngles.y < anguloFinal) {
					transform.Rotate (0, 0.5f, 0, Space.World);
					yield return new WaitForSeconds (0.01f);
				}
			}

		} else { //Giro a izquierda
			while ((transform.rotation.eulerAngles.y < anguloFinal) & (transform.rotation.eulerAngles.y <= posinicial)) {
				transform.Rotate (0, -0.5f, 0, Space.World);
				yield return new WaitForSeconds (0.01f);
			}
			if (transform.rotation.eulerAngles.y > anguloFinal) {
				while (transform.rotation.eulerAngles.y > anguloFinal) {
					transform.Rotate (0, -0.5f, 0, Space.World);
					yield return new WaitForSeconds (0.01f);
				}
			}
			
		}

		yield return new WaitForSeconds (1f);
		girar = false;

		
	}

	public  void jsAvanzar(double velocidad, int segundos) {

		StartCoroutine (corutinaAvanzar (velocidad, segundos));


	}

	IEnumerator corutinaAvanzar (double velocidad, int segundos){
		while (girar || avanzar) {
			yield return null;
		}
		tiempoAvance = Time.time + segundos;
		avanzar = true;
		velocidadAvance = (float)velocidad;
		while (Time.time < tiempoAvance ) {
			Debug.Log("Avanzando a " + velocidadAvance + " durante " + segundos + " segundos");
			//rb.velocity = Vector3.forward * velocidadAvance * Time.deltaTime * 10;
			transform.Translate (Vector3.forward * velocidadAvance * 0.01f);
			yield return new WaitForSeconds (0.01f);
		}

		yield return new WaitForSeconds (1f);
		avanzar = false;

	}

	public void jsPrint(string cadena) { Debug.Log(cadena); }
	
	public void jsSetPos(double x, double y, double z)
	{
		
		transform.position = new Vector3((float)x, (float)y, (float)z);
	}

	public void jsAddForce(double d, double d1, double d2) { 

		Debug.Log ("Entro aquí");

		Rigidbody rb = (Rigidbody)GetComponent<Rigidbody> ();
		float f = (float)d;
		float f1 = (float)d1;
		float f2 = (float)d2;
		rb.AddForce(f, f1, f2, ForceMode.VelocityChange);
	}
	
	
	// Implementation of the JS functions for get/setting position by passing and returning
	// instances of our custom JS Vector class which is a supported type in Jurassic because
	// we derived it from Jurassic.Library.ObjectInsance.
	public jsVectorInstance jsGetPos()
	{
		return new jsVectorConstructor(engine).Construct(
			(double)transform.position.x,
			(double)transform.position.y,
			(double)transform.position.z);
	}
	
	public void jsSetPosVec(jsVectorInstance pos)
	{
		double x = TypeConverter.ConvertTo<double>(engine, pos.GetPropertyValue("x"));
		double y = TypeConverter.ConvertTo<double>(engine, pos.GetPropertyValue("y"));
		double z = TypeConverter.ConvertTo<double>(engine, pos.GetPropertyValue("z"));
		transform.position = new Vector3((float)x, (float)y, (float)z);
	}
	
	
	// Implementation of the JS GetText and SetText functions.
    public string jsGetText() { return floatingText; }
    public void jsSetText(string text) { floatingText = text; }	
	
	#endregion

	// Unity stuff.
	void FixedUpdate()
	{
		//Example of modifying a global variable.  You can use GetGlobalValue to access a global variable.
		engine.SetGlobalValue("time", Time.time);
			
	}

	IEnumerator Ejecutar(){
		//yield return new WaitForSecondsRealtime(2);
		engine.Execute(codeString);
		yield return null;


	}
	
	void OnGUI()
	{
		//Display the contents of the JS GetText and SetText string using a GUI.Label
		Vector3 c = Camera.main.WorldToScreenPoint(transform.position);
		GUI.Label(new Rect(c.x, Screen.height-c.y, 100, 100), floatingText);

		//Script editor GUI
		//GUI.skin = editorStyle;
		GUILayout.BeginArea(new Rect(10, 10, 300, Screen.height-20));
		GUILayout.BeginVertical();		
		codeString = GUILayout.TextArea(codeString, GUILayout.ExpandHeight(true));		
		GUILayout.BeginHorizontal();
		running = GUILayout.Toggle(running, "Running");
		if (GUILayout.Button ("Test Execute"))
			StartCoroutine (Ejecutar ()); 
		GUILayout.EndHorizontal();
		GUILayout.EndVertical();
		GUILayout.EndArea();
	}
}

#region Implementation of our custom static JavaScript Day class
// This is the implementation of the JavaScript Day class which just returns next/prev 
// string from an array for the purpose of demonstrating a custom static class in JS.
public class jsDayIterator : ObjectInstance
{
	private string[] days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	private int i;
	
    public jsDayIterator(ScriptEngine engine) 
		: base(engine)	    
	{
		//PopulateFunctions searches the class for JSFunction attributes and creates a function for each one it finds.
    	this.PopulateFunctions();
    }
	
	//The JSFunction attribute's Name parameter allows the function name in JS to be different than in .NET
    [JSFunction(Name = "Next")]
    public string jsNext()
    {
		i += 1;
		i %= 7;
        return days[i];
    }
	
	[JSFunction(Name = "Prev")]
    public string jsPrev()
    {
        i -= 1;
		if (i==-1) i+=7;
		i %= 7;
        return days[i];
    }
	
	[JSFunction(Name = "Set")]
    public string jsSet(int n)
    {
        i = n % 7;
        return days[i];
    }
}
#endregion


#region Implementation of our custom JavaScript Vector class
// Objects that can be instantiated, like the built-in Number, String, Array and RegExp objects, require two .NET classes,
// one for the constructor and one for the instance. For more info see "Building an instance class" here:
// http://jurassic.codeplex.com/wikipage?title=Exposing%20a%20.NET%20class%20to%20JavaScript

//This is the constructor class for the JS Vector class.
public class jsVectorConstructor : ClrFunction
{
    public jsVectorConstructor(ScriptEngine engine)
		: base(engine.Function.InstancePrototype, "Vector", new jsVectorInstance(engine.Object.InstancePrototype))
    {}
	
	//The JSConstructorFunction attribute marks the method that is called when the new operator is used to create an instance in a JavaScript
    [JSConstructorFunction]
    public jsVectorInstance Construct(double x, double y, double z)
    {
        return new jsVectorInstance(this.InstancePrototype, x, y, z);
    }
}

//This is the instance class for the JS Vector class.
public class jsVectorInstance : ObjectInstance
{
    public jsVectorInstance(ObjectInstance prototype)
		: base(prototype)
    {
        this.PopulateFunctions();
    }

    public jsVectorInstance(ObjectInstance prototype, double x, double y, double z) : base(prototype)
    {
		this.SetPropertyValue("x", x, true);
		this.SetPropertyValue("y", y, true);
		this.SetPropertyValue("z", z, true);
    }
	
	[JSFunction]
	public void Reset()
	{
		this.SetPropertyValue("x", 139.1, true);
		this.SetPropertyValue("y", 3.6, true);
		this.SetPropertyValue("z", -63.1, true);
	}
}

#endregion