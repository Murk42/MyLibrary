vcpkg_from_github(
	OUT_SOURCE_PATH SOURCE_PATH
	REPO Murk42/MyLibrary
	REF de72035e76c167ea4be24716ec2dae10710fbd39
	SHA512 1
	HEAD_REF master
)

vcpkg_configure_cmake(
	SOURCE_PATH "${SOURCE_PATH}"
	PREFER_NINJA
)
vcpkg_install_cmake()
vcpkg_fixup_cmake_targets()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(
	INSTALL "${SOURCE_PATH}/LICENSE"
	DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
	RENAME copyright)
