DESCRIPTION = "Simple hello world application"
LICENSE = "MIT"

SRC_URI = "file://hello.c"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

S = "${WORKDIR}"

do_compile() {
	${CC} hello.c ${LDFLAGS} -o helloyocto
}

do_install() {
	install -d ${D}${bindir}
	install -m 0755 helloyocto ${D}${bindir}
}