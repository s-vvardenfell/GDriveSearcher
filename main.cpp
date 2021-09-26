#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <gdrive_handler.hpp>
#include <beast_handler.hpp>

using namespace std;

int main()
{

    GDriveHandler handler;
    handler.query("windows", "");

//    BeastHandler beast;
////    beast.get("agregatoreat.ru", "https://agregatoreat.ru/catalog/categories");

//    const std::string body = R"({"page":1,"size":10,"isReviewAwaiting":false,"isCustomerSigningAwaiting":false,"isSupplierSigningAwaiting":false,"isChangeDealTermsProtocolReceived":false,"searchText":"kaspersky","purchaseName":"","number":null,"lotItemEatCodes":[],"productCode":null,"okpd2Codes":[],"ktruCodes":[],"purchaseTypeIds":[],"types":[],"customerNameOrInn":null,"customerInn":null,"customerKpp":null,"supplierNameOrInn":null,"purchaseMethods":[1],"priceStart":null,"priceEnd":null,"deliveryAddressRegionCodes":[],"deliveryAddress":null,"contractPriceStart":null,"contractPriceEnd":null,"applicationFillingStartDate":null,"applicationFillingEndDate":null,"contractSignDateStart":null,"contractSignDateEnd":null,"deliveryDateStart":null,"deliveryDateEnd":null,"isSmpOnly":false,"stateDefenseOrderOnly":false,"createDateTime":null,"excludeCancelledByCustomer":false,"lotStates":[],"sort":[{"fieldName":"publishDate","direction":2}]})";
////        string_view body2 = "%22page%22%3A1%2C%22size%22%3A10%2C%22isReviewAwaiting%22%3Afalse%2C%22isCustomerSigningAwaiting%22%3Afalse%2C%22isSupplierSigningAwaiting%22%3Afalse%2C%22isChangeDealTermsProtocolReceived%22%3Afalse%2C%22searchText%22%3A%22kaspersky%22%2C%22purchaseName%22%3A%22%22%2C%22number%22%3Anull%2C%22lotItemEatCodes%22%3A%5B%5D%2C%22productCode%22%3Anull%2C%22okpd2Codes%22%3A%5B%5D%2C%22ktruCodes%22%3A%5B%5D%2C%22purchaseTypeIds%22%3A%5B%5D%2C%22types%22%3A%5B%5D%2C%22customerNameOrInn%22%3Anull%2C%22customerInn%22%3Anull%2C%22customerKpp%22%3Anull%2C%22supplierNameOrInn%22%3Anull%2C%22purchaseMethods%22%3A%5B1%5D%2C%22priceStart%22%3Anull%2C%22priceEnd%22%3Anull%2C%22deliveryAddressRegionCodes%22%3A%5B%5D%2C%22deliveryAddress%22%3Anull%2C%22contractPriceStart%22%3Anull%2C%22contractPriceEnd%22%3Anull%2C%22applicationFillingStartDate%22%3Anull%2C%22applicationFillingEndDate%22%3Anull%2C%22contractSignDateStart%22%3Anull%2C%22contractSignDateEnd%22%3Anull%2C%22deliveryDateStart%22%3Anull%2C%22deliveryDateEnd%22%3Anull%2C%22isSmpOnly%22%3Afalse%2C%22stateDefenseOrderOnly%22%3Afalse%2C%22createDateTime%22%3Anull%2C%22excludeCancelledByCustomer%22%3Afalse%2C%22lotStates%22%3A%5B%5D%2C%22sort%22%3A%5B%7B%22fieldName%22%3A%22publishDate%22%2C%22direction%22%3A2";

//    beast.post("tender-cache-api.agregatoreat.ru",
//               "https://agregatoreat.ru/api/TradeLot/list-published-trade-lots", body);








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
