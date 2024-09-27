#ifndef DB31787D_5B51_49C1_BEF8_D4311A3899C4
#define DB31787D_5B51_49C1_BEF8_D4311A3899C4

#ifndef myTypes_h
#define myTypes_h

#include <WString.h>
#include <string>
#include <vector>
#include "Singleton.hpp"
#include "WiFi.h"
#include "PersistanceData.hpp"
#include "Logger.hpp"

#define MAX_CONFIG_DATA_SIZE 4096

class EEPROMHandler final : public Singleton<EEPROMHandler>
{
  friend class Singleton<EEPROMHandler>;

public:
  void init(NVData_t &data);
  void AssumeDefaults();
  void Store(NVData_t data);

private:
  EEPROMHandler()
  {
    mLogger = new Logger("EEPROMHandler");
  }
  ~EEPROMHandler() {}
  void eraseData();
  Logger *mLogger = nullptr;
};

#endif

#endif /* DB31787D_5B51_49C1_BEF8_D4311A3899C4 */
