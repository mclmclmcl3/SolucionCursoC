//#pragma once
//
//// Including the necessary libraries for the WinRT HTTP server.
//#include <winrt/Windows.Foundation.h>
//#include <winrt/Windows.Web.Http.h>
//#include <winrt/Windows.Web.Http.Filters.h>
//#include <winrt/Windows.Web.Http.Headers.h>
//#include <future>
//#include <iostream>
//
//using namespace winrt::Windows::Web::Http;
//using namespace winrt::Windows::Foundation;
//using namespace std;
//
///**
//* @class HTTPServer
//* Represents a simple HTTP server using WinRT APIs.
//*/
//class HTTPServer {
//private:
//	Filters::HttpBaseProtocolFilter m_filter;
//	HttpClient m_client;
//	HttpRequestMessage m_request;
//	HttpResponseMessage m_response;
//
//public:
//	/**
//	* Constructs an HTTP server object.
//	*/
//	HTTPServer() {
//		// Initialize the HTTP client and request objects.
//		m_client = HttpClient();
//		m_request = HttpRequestMessage();
//	}
//
//	/**
//	* Sends an HTTP GET request to the specified URL and returns the response.
//	*
//	* @param url The URL to send the GET request to.
//	* @return winrt::Windows::Web::Http::HttpResponseMessage The response from the server.
//	*/
//
//	HttpResponseMessage SendGetRequest(const Uri& url) {
//		// Set the request URI.
//		m_request.RequestUri(url);
//
//		// Send the GET request and wait for the response.
//		m_response = m_client.SendRequestAsync(m_request).get();
//
//		return m_response;
//	}
//};
//
