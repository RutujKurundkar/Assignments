#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

enum class HttpStatus {
    OK           = 200,
    Created      = 201,
    BadRequest   = 400,
    Unauthorized = 401,
    NotFound     = 404,
    ServerError  = 500
};

void handleResponse(HttpStatus status, const string& endpoint) {
    string padding = "";
    if (endpoint == "[GET /api/users]" || endpoint == "[POST /api/login]") {
        padding = "      ";
    } else if (endpoint == "[POST /api/order]") {
        padding = "      ";
    }

    cout << endpoint << padding << " -> " << static_cast<int>(status) << " ";

    switch (status) {
        case HttpStatus::OK:
            cout << "OK             : Request successful" << endl;
            break;
        case HttpStatus::Created:
            cout << "Created        : Resource created successfully" << endl;
            break;
        case HttpStatus::BadRequest:
            cout << "Bad Request    : Invalid request syntax" << endl;
            break;
        case HttpStatus::Unauthorized:
            cout << "Unauthorized   : Authentication required" << endl;
            break;
        case HttpStatus::NotFound:
            cout << "Not Found      : Endpoint does not exist" << endl;
            break;
        case HttpStatus::ServerError:
            cout << "Server Error   : Internal server error – retry later" << endl;
            break;
        default:
            cout << "Unknown        : Unknown status code status" << endl;
            break;
    }
}

using Header     = pair<string, string>;
using HeaderList = vector<Header>;
using Port       = unsigned int;
using IPAddress  = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {
    cout << "Headers:\n";
    for (const auto& header : headers) {
        string padding = "";
        if (header.first == "Content-Type") {
            padding = "   ";
        } else if (header.first == "Authorization") {
            padding = "  ";
        }

        cout << "  " << header.first << padding << " : " << header.second << endl;
    }
}

int main() {
    handleResponse(HttpStatus::OK, "[GET /api/users]");
    handleResponse(HttpStatus::Unauthorized, "[POST /api/login]");
    handleResponse(HttpStatus::NotFound, "[GET /api/products/99]");
    handleResponse(HttpStatus::ServerError, "[POST /api/order]");

    cout << "\n--------------------------------------------------\n\n";

    RequestId reqId = 1748293847;
    Port serverPort = 8080;

    HeaderList headers = {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    cout << "Request ID   : " << reqId << endl;
    cout << "Server Port  : " << serverPort << endl;
    cout << endl;

    printHeaders(headers);

    return 0;
}
