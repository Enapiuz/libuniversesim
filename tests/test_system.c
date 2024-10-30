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
  TEST_ASSERT_EQUAL(UNISIM_ERROR_NOT_INITIALIZED, uns_System_Init());
  TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Shutdown());
}

void test_uns_System_Shutdown_Uninited_Failure(void) {
  TEST_ASSERT_EQUAL(UNISIM_ERROR_NOT_INITIALIZED, uns_System_Shutdown());
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_uns_System_Init);
  RUN_TEST(test_uns_System_Shutdown);
  RUN_TEST(test_uns_Simulation_Create);
  RUN_TEST(test_uns_System_Double_Init_Failure);
  RUN_TEST(test_uns_System_Shutdown_Uninited_Failure);
  return UNITY_END();
}
