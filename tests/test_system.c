#include "unity.h"
#include "universesim/universesim.h"

void setUp(void) {}

void tearDown(void) {}

void test_uns_System_Init(void) { TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Init()); }

void test_uns_System_Shutdown(void) { TEST_ASSERT_EQUAL(UNISIM_OK, uns_System_Shutdown()); }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_uns_System_Init);
  RUN_TEST(test_uns_System_Shutdown);
  return UNITY_END();
}
