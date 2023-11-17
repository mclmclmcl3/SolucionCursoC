
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Web.Http.Headers.h>
#include <winrt/Windows.Data.Json.h>
#include <iostream>

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Http;
using namespace Windows::Data::Json;

int HttpGetAll(Uri requestUri);
int HttpGetById(int id, Uri requestUri);



int main()
{
	init_apartment();
	Uri requestUri{ L"http://api.marianonet.com/api/ActividadFisica" };

	//Uri baseUri{ L"http://api.marianonet.com/api/" };
	//Uri relativeUri{ L"ActividadFisica" };

	//Uri requestUri = baseUri / relativeUri;

	HttpGetAll(requestUri);
	// HttpGetById(1, requestUri); // No está operativo, hay que buscar una API que pueda sacar por id


	system("pause");
	return 0;
}

int HttpGetAll(Uri requestUri)
{
	HttpClient httpClient{};
	HttpResponseMessage httpResponseMessage;
	hstring httpResponseBody;

	try
	{
		// Realiza la solicitud HTTP y espera a que se complete.
		httpResponseMessage = httpClient.GetAsync(requestUri).get();
		httpResponseMessage.EnsureSuccessStatusCode();

		// Lee el cuerpo de la respuesta como cadena de manera asíncrona y espera a que se complete.
		httpResponseBody = httpResponseMessage.Content().ReadAsStringAsync().get();
	}
	catch (winrt::hresult_error const& ex)
	{
		wcerr << L"Error HRESULT: " << ex.code().value << L" - " << ex.message().c_str() << endl;
		return -1;
	}
	catch (const winrt::hresult_access_denied& ex)
	{
		wcerr << L"Error de acceso denegado: " << ex.message().c_str() << endl;
		return -1;
	}
	catch (const winrt::hresult_invalid_argument& ex)
	{
		wcerr << L"Error de argumento no válido: " << ex.message().c_str() << endl;
		return -1;
	}
	catch (const winrt::hresult_wrong_thread& ex)
	{
		wcerr << L"Error en el hilo incorrecto: " << ex.message().c_str() << endl;
		return -1;
	}
	catch (const winrt::hresult_not_implemented& ex)
	{
		wcerr << L"Error: Método no implementado: " << ex.message().c_str() << endl;
		return -1;
	}
	catch (const winrt::hresult_out_of_bounds& ex)
	{
		wcerr << L"Error: Índice fuera de límites: " << ex.message().c_str() << endl;
		return -1;
	}
	catch (...)
	{
		wcerr << L"Error desconocido." << endl;
		return -1;
	}

	try
	{
		// Ahora puedes analizar el cuerpo de la respuesta.
		JsonValue jsonValue = JsonValue::Parse(httpResponseBody);

		// Verifica si el valor JSON es un arreglo.
		if (jsonValue.ValueType() == JsonValueType::Array)
		{
			JsonArray jsonArray = jsonValue.GetArray();

			// Itera sobre los elementos del arreglo.
			for (uint32_t i = 0; i < jsonArray.Size(); ++i)
			{
				JsonObject jsonObject = jsonArray.GetObjectAt(i);

				// Verifica si la propiedad "nombre" existe en el objeto JSON.
				if (jsonObject.HasKey(L"nombre"))
				{
					hstring Name = jsonObject.GetNamedString(L"nombre");
					wcout << L"nombre: " << Name.c_str() << endl;
				}
				else
				{
					wcerr << L"La propiedad 'nombre' no está presente en el objeto JSON." << endl;
				}

				// Verifica si la propiedad "nivelActividad" existe en el objeto JSON.
				if (jsonObject.HasKey(L"nivelActividad"))
				{
					int nivelActividad = static_cast<int>(jsonObject.GetNamedNumber(L"nivelActividad"));
					wcout << L"nivelActividad: " << nivelActividad << endl;
				}
				else
				{
					wcerr << L"La propiedad 'nivelActividad' no está presente en el objeto JSON." << endl;
				}
			}
		}
		else
		{
			wcerr << L"El valor JSON no es un arreglo." << endl;
		}
	}
	catch (winrt::hresult_error const& ex)
	{
		wcerr << L"Error al analizar el JSON: " << ex.message().c_str() << endl;
		return -1;
	}


}

int HttpGetById(int id, Uri requestUri)
{
	HttpClient httpClient{};
	HttpResponseMessage httpResponseMessage;
	hstring httpResponseBody;

	try
	{
		// Ahora puedes analizar el cuerpo de la respuesta.
		JsonValue jsonValue = JsonValue::Parse(httpResponseBody);

		// Verifica si el valor JSON es un objeto antes de intentar extraer propiedades.
		if (jsonValue.ValueType() == JsonValueType::Object)
		{
			JsonObject jsonObject = jsonValue.GetObject();

			// Verifica si la propiedad "name" existe en el objeto JSON.
			if (jsonObject.HasKey(L"nombre"))
			{
				hstring Name = jsonObject.GetNamedString(L"nombre");
				wcout << L"nombre: " << Name.c_str() << endl;
			}
			else
			{
				wcerr << L"La propiedad 'nombre' no está presente en el objeto JSON." << endl;
			}

			// Verifica si la propiedad "fees" existe en el objeto JSON.
			if (jsonObject.HasKey(L"nivelActividad"))
			{
				int Fees = static_cast<int>(jsonObject.GetNamedNumber(L"nivelActividad"));
				wcout << L"nivelActividad: " << Fees << endl;
			}
			else
			{
				wcerr << L"La propiedad 'nivelActividad' no está presente en el objeto JSON." << endl;
			}
		}
		else
		{
			wcerr << L"El valor JSON no es un objeto." << endl;
		}
	}
	catch (winrt::hresult_error const& ex)
	{
		wcerr << L"Error al analizar el JSON: " << ex.message().c_str() << endl;
		return -1;
	}

}