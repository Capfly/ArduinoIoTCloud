/*
   Copyright (c) 2019 Arduino.  All rights reserved.
*/

/**************************************************************************************
   INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <util/CBORTestUtil.h>
#include <ArduinoCloudThing.h>

/**************************************************************************************
   TEST CODE
 **************************************************************************************/

SCENARIO("A Arduino cloud property is published on value change", "[ArduinoCloudThing::publishOnChange]") {
  /************************************************************************************/

  GIVEN("CloudProtocol::V2") {
    PropertyContainer property_container;
    ArduinoCloudThing thing;
    thing.begin(&property_container);

    CloudInt       test  = 10;
    int const DELTA = 6;

    property_container.addPropertyReal(test, "test", Permission::ReadWrite).publishOnChange(DELTA);

    WHEN("test = 10, delta = 6, the property is encoded for the 1st time") {
      THEN("The property should be encoded") {
        REQUIRE(cbor::encode(thing).size() != 0);
        WHEN("test +=4 -> test = 14") {
          test += 4;
          THEN("Since the increment since the last update (4) is smaller than the delta of 6 the property should not be encoded") {
            REQUIRE(cbor::encode(thing).size() == 0);
            WHEN("test +=4 -> test = 18") {
              test += 4;
              THEN("Since the increment since the last update (8) is greater than the delta of 6 the property should be encoded") {
                REQUIRE(cbor::encode(thing).size() != 0);
              }
            }
          }
        }
      }
    }
  }

  /************************************************************************************/
}
