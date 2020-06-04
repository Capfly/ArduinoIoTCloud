/*
   Copyright (c) 2019 Arduino.  All rights reserved.
*/

/**************************************************************************************
   INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <PropertyContainer.h>

#include <types/CloudInt.h>
#include <types/CloudBool.h>
#include <types/CloudFloat.h>
#include <types/CloudString.h>

/**************************************************************************************
   TEST CODE
 **************************************************************************************/

SCENARIO("The same arduino cloud properties are added multiple times", "[ArduinoCloudThing::addPropertyReal]") {
  WHEN("The same bool property is added multiple times") {
    PropertyContainer property_container;

    CloudBool bool_property = false;

    ArduinoCloudProperty * bool_property_ptr_1 = &property_container.addPropertyReal(bool_property, "bool_property", Permission::ReadWrite);
    ArduinoCloudProperty * bool_property_ptr_2 = &property_container.addPropertyReal(bool_property, "bool_property", Permission::ReadWrite);
    THEN("No new property is added and the first added property is returned instead of a new one") {
      REQUIRE(bool_property_ptr_1 == bool_property_ptr_2);
    }
  }

  /**************************************************************************************/

  WHEN("the same int property is added multiple times") {
    PropertyContainer property_container;

    CloudInt int_property = 1;

    ArduinoCloudProperty * int_property_ptr_1 = &property_container.addPropertyReal(int_property, "int_property", Permission::ReadWrite);
    ArduinoCloudProperty * int_property_ptr_2 = &property_container.addPropertyReal(int_property, "int_property", Permission::ReadWrite);

    THEN("No new property is added and the first added property is returned instead of a new one") {
      REQUIRE(int_property_ptr_1 == int_property_ptr_2);
    }
  }

  /**************************************************************************************/

  WHEN("the same float property is added multiple times") {
    PropertyContainer property_container;

    CloudFloat float_property = 1.0f;

    ArduinoCloudProperty * float_property_ptr_1 = &property_container.addPropertyReal(float_property, "float_property", Permission::ReadWrite);
    ArduinoCloudProperty * float_property_ptr_2 = &property_container.addPropertyReal(float_property, "float_property", Permission::ReadWrite);

    THEN("No new property is added and the first added property is returned instead of a new one") {
      REQUIRE(float_property_ptr_1 == float_property_ptr_2);
    }
  }

  /**************************************************************************************/

  WHEN("the same String property is added multiple times") {
    PropertyContainer property_container;

    CloudString str_property;

    ArduinoCloudProperty * str_property_ptr_1 = &property_container.addPropertyReal(str_property, "str_property", Permission::ReadWrite);
    ArduinoCloudProperty * str_property_ptr_2 = &property_container.addPropertyReal(str_property, "str_property", Permission::ReadWrite);

    THEN("No new property is added and the first added property is returned instead of a new one") {
      REQUIRE(str_property_ptr_1 == str_property_ptr_2);
    }
  }
}