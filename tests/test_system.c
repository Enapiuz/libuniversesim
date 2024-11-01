#include "../src/container.h"
#include "unity.h"
#include "universesim/universesim.h"

void setUp(void) {}

void tearDown(void) {}

void test_uns_System_Init(void) { TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Init()); }

void test_uns_System_Shutdown(void) { TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Shutdown()); }

void test_uns_Simulation_Create(void) {
  unsId simId;
  TEST_ASSERT_EQUAL(UNISIM_OK, uns_Simulation_Create("path/to/logic", "path/to/db", &simId));
  TEST_ASSERT_EQUAL(0, simId);
}

void test_uns_System_Double_Init_Failure(void) {
  TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Init());
  TEST_ASSERT_EQUAL(UNISIM_ERROR_ALREADY_INITIALIZED, uns_System_Init());
  TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Shutdown());
}

void test_uns_System_Shutdown_Uninited_Failure(void) {
  TEST_ASSERT_EQUAL(UNISIM_ERROR_NOT_INITIALIZED, uns_System_Shutdown());
}

void test_uns_Container_Push() {
  uns_System_Init();
  uns_Simulation simulation = {0};
  TEST_ASSERT_EQUAL(UNISIM_OK, uns_Container_Push(&simulation));

  uns_Simulation simulationTwo = {.version = 1};
  TEST_ASSERT_EQUAL(UNISIM_OK, uns_Container_Push(&simulationTwo));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_uns_System_Init);
  RUN_TEST(test_uns_System_Shutdown);
  RUN_TEST(test_uns_Simulation_Create);
  RUN_TEST(test_uns_System_Double_Init_Failure);
  RUN_TEST(test_uns_System_Shutdown_Uninited_Failure);
  RUN_TEST(test_uns_Container_Push);
  return UNITY_END();
}
