#ifndef EC3C3C58_5914_4752_AA60_98803688D427
#define EC3C3C58_5914_4752_AA60_98803688D427

#include "Logger.hpp"
#include <string>

#define MAX_VALIDATION_STRING 9
#define MAX_LENGTH_SSID 30
#define MAX_LENGTH_PASSWD 30
#define MAX_LENGTH_TOPIC 63
#define MAX_LENGTH_HNAME 30
#define VALID_STRING "valid"
#define INVALID_STRING "invalid"

typedef struct
{

    int NVDataSize;
    char validation[MAX_VALIDATION_STRING + 1];

} NVDataHeader_t;

// Types 'byte' and 'word' doesn't work!
typedef struct
{
    // int valid;                     /// 0=no configuration, 1=valid configuration
    char eSsid[MAX_LENGTH_SSID + 1];     ///< SSID of WiFi
    char ePass[MAX_LENGTH_PASSWD + 1];   ///< Password of WiFi
    char hostname[MAX_LENGTH_HNAME + 1]; ///< Hostname the controller responds to in any WiFi Network
    char apName[31];                     ///< AccessPoint name the controller will advertise if no WiFi Network is available
} WiFiConfigData_t;

typedef struct
{

    char mqttServer[MAX_LENGTH_HNAME] = "homeautomationserver"; ///< IP of MQTT server (maybe replaced by define)
    int mqttPort = 1883;                                        ///< Port of MQTT server (maybe replaced by define)

} mqttConfig_t;

typedef struct
{

    NVDataHeader_t Header;
    WiFiConfigData_t WifiConf;
    mqttConfig_t mqttConf;

} NVData_t;

const std::string className = "PersistanceData";

class PersistanceData
{

public:
    PersistanceData();

    // Setters
    void storeSSID(const std::string newSSID);
    void storePassWd(const std::string newPassWd);
    void setHostname(const std::string newHostname);
    void setBrokerAddress(const std::string newBrokerAddress);

    // Getters
    std::string getHostname() { return std::string(NVData.WifiConf.hostname); }
    std::string getSsid() { return std::string(NVData.WifiConf.eSsid); }
    std::string getPassword() { return std::string(NVData.WifiConf.ePass); }
    std::string getMqttBrokerAddress() { return std::string(NVData.mqttConf.mqttServer); }
    int getMqttBrokerPort() { return NVData.mqttConf.mqttPort; }

    // IPAddress getMqttBrokerIp()
    // {
    //     IPAddress ip;
    //     WiFiGenericClass::hostByName(m_BrokerAddresse.c_str(), ip);
    //     return ip;
    // }

private:
    // Stored Parameters
    std::string m_hostname{"defaultHostname"};
    std::string m_ssid{""};
    std::string m_password{""};
    std::string m_BrokerAddresse{"homeautomationserver"};
    int m_BrokerPort{1883};

    NVData_t NVData;
    Logger *mLogger = nullptr;

    void restoreDefaults();
};

#endif /* EC3C3C58_5914_4752_AA60_98803688D427 */
