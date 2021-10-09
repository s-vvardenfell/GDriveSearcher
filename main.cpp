#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <gdrive_handler.hpp>
#include <beast_handler.hpp>
#include <curl_handler.hpp>

using namespace std;

const std::string getHostFromURL(const string &url)
{

}

int main()
{
//    const std::string body = R"({"page":1,"size":10,"isReviewAwaiting":false,"isCustomerSigningAwaiting":false,"isSupplierSigningAwaiting":false,"isChangeDealTermsProtocolReceived":false,"searchText":"kaspersky","purchaseName":"","number":null,"lotItemEatCodes":[],"productCode":null,"okpd2Codes":[],"ktruCodes":[],"purchaseTypeIds":[],"types":[],"customerNameOrInn":null,"customerInn":null,"customerKpp":null,"supplierNameOrInn":null,"purchaseMethods":[1],"priceStart":null,"priceEnd":null,"deliveryAddressRegionCodes":[],"deliveryAddress":null,"contractPriceStart":null,"contractPriceEnd":null,"applicationFillingStartDate":null,"applicationFillingEndDate":null,"contractSignDateStart":null,"contractSignDateEnd":null,"deliveryDateStart":null,"deliveryDateEnd":null,"isSmpOnly":false,"stateDefenseOrderOnly":false,"createDateTime":null,"excludeCancelledByCustomer":false,"lotStates":[],"sort":[{"fieldName":"publishDate","direction":2}]})";

//    GDriveHandler handler;
//    handler.query("windows", "");

    BeastHandler beast;
    beast.get("https://www.b2b-center.ru/market/?f_keyword=1%D1%81&searching=1&company_type=2&price_currency=0&date=1&trade=all#search-result");

//    string url = "<a href=https://www.b2b-center.ru/auth/server/?action=track&amp;a=MDAwMDAwMDAwMDAwMDAwMMWdSEhhDhgrWuROjhjISaHavqnXvUC8gwCmlguuOpEORSC-p8Xl8masvaxgtYrWa_i-KlLw2oL-VAHOYqMZ01JSCLU-r8YeGp7FChPLjS7-DOehANvFrDhyDjKXm5xo4pEbJbmz5_KCGJFqz3wayVgjZ_0AgnTqlZtDrntQDvKYWXpTu8IALn2d0W5Mt9V-PdP0tzPAbNHGkck4lltDkZVeVNqKYmoGY8W4zXFvlWf4-5ietLkv8m9V-QHgfpucT4dFVlWPqb9FBFwFmMB2fRJ_JRuBLROyg4UvvmzSxOt-tZ7ucs4_zi_LzyjUqiQOw8ksiWQ2_Kz6OwpOfpfNmTISHgrPktZ1a_N8RPD5XVf9vbx1p8oSzoHd11imm4JUAZVTc8mGTPv4GTflx3dsiESL82vE6bYrltV8p5OThKYHalIlfzORJSOIDrfwMe4tyQPsegoevvMqZHzwpDutDjuoRB4TDEFvptYFhWVQcR6efR5rvEhoVMANOn94nJe4AA%7E%7E>Продолжить &gt;&gt;";
//    string url2 = "https://www.b2b-center.ru/market/?f_keyword=1%D1%81&searching=1&company_type=2&pric";
//    cout<<Utility::parseDataFromPage(url2, "https://", "/", false);


//    beast.get("www.b2b-center.ru", "https://www.b2b-center.ru/market/?f_keyword=1%D1%81&searching=1&company_type=2&price_currency=0&date=1&trade=all#search-result");

//    beast.post("tender-cache-api.agregatoreat.ru",
//               "https://agregatoreat.ru/api/TradeLot/list-published-trade-lots", body);



//    CurlHandler curl;

//    curl.query("https://www.b2b-center.ru/market/?f_keyword=1%D1%81&searching=1&company_type=2&price_currency=0&date=1&trade=all#search-result", methodType::GET);
//    curl.query("https://agregatoreat.ru/api/TradeLot/list-published-trade-lots", methodType::POST, body);
//    Utility::saveDocument("log.txt", curl.getResponse());


//#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    return app.exec();



}
