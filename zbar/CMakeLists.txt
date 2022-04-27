cmake_minimum_required(VERSION 3.23)

project(zbar C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_definitions(
    -DHAVE_LIBJPEG
    -DDEBUG_SVG
    -DHAVE_POLL_H=0
    )

set(CMAKE_CXX_FLAGS "--data-sections")

message(CFLAGS=${CFLAGS})
message(CXXFLAGS=${CMAKE_CXX_FLAGS})
message($ENV{LIBGNUWIN32}/include/)

# set(CMAKE_c "-DHAVE_LIBJPEG=1")



add_library(${PROJECT_NAME} "")

target_include_directories(${PROJECT_NAME} 
	PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/.
    ${CMAKE_CURRENT_LIST_DIR}/../include/
    ${CMAKE_CURRENT_LIST_DIR}/../include/zbar/
	${CMAKE_CURRENT_LIST_DIR}/decoder/
	${CMAKE_CURRENT_LIST_DIR}/processor/
    ${CMAKE_CURRENT_LIST_DIR}/qrcode/
	${CMAKE_CURRENT_LIST_DIR}/video/
    ${CMAKE_CURRENT_LIST_DIR}/window/
    $ENV{LIBGNUWIN32}/include/
    $ENV{LIBGNUWIN32}/include/libpng12
    $ENV{LIBPTHREAD}/include/
    # ${CMAKE_CURRENT_LIST_DIR}/window/
    ${CMAKE_CURRENT_LIST_DIR}/../external/stb
)

target_sources(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/config.c
  ${CMAKE_CURRENT_LIST_DIR}/convert.c
  ${CMAKE_CURRENT_LIST_DIR}/debug.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder.h
  ${CMAKE_CURRENT_LIST_DIR}/error.c
  ${CMAKE_CURRENT_LIST_DIR}/error.h
  ${CMAKE_CURRENT_LIST_DIR}/image.c
  ${CMAKE_CURRENT_LIST_DIR}/image.h
  ${CMAKE_CURRENT_LIST_DIR}/img_scanner.c
  ${CMAKE_CURRENT_LIST_DIR}/img_scanner.h
  ${CMAKE_CURRENT_LIST_DIR}/jpeg.c
  ${CMAKE_CURRENT_LIST_DIR}/misc.c
  ${CMAKE_CURRENT_LIST_DIR}/misc.h
  ${CMAKE_CURRENT_LIST_DIR}/mutex.h
  ${CMAKE_CURRENT_LIST_DIR}/processor.c
  ${CMAKE_CURRENT_LIST_DIR}/processor.h
  ${CMAKE_CURRENT_LIST_DIR}/qrcode.h
  ${CMAKE_CURRENT_LIST_DIR}/refcnt.c
  ${CMAKE_CURRENT_LIST_DIR}/refcnt.h
  ${CMAKE_CURRENT_LIST_DIR}/scanner.c
  ${CMAKE_CURRENT_LIST_DIR}/sqcode.c
  ${CMAKE_CURRENT_LIST_DIR}/sqcode.h
  ${CMAKE_CURRENT_LIST_DIR}/svg.c
  ${CMAKE_CURRENT_LIST_DIR}/svg.h
  ${CMAKE_CURRENT_LIST_DIR}/symbol.c
  ${CMAKE_CURRENT_LIST_DIR}/symbol.h
  ${CMAKE_CURRENT_LIST_DIR}/thread.h
  ${CMAKE_CURRENT_LIST_DIR}/timer.h
  ${CMAKE_CURRENT_LIST_DIR}/video.c
  ${CMAKE_CURRENT_LIST_DIR}/video.h
  ${CMAKE_CURRENT_LIST_DIR}/window.c
  ${CMAKE_CURRENT_LIST_DIR}/window.h
  
  ${CMAKE_CURRENT_LIST_DIR}/decoder/codabar.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/codabar.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/code39.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/code39.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/code93.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/code93.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/code128.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/code128.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/databar.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/databar.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/ean.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/ean.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/i25.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/i25.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/pdf417_hash.h
  ${CMAKE_CURRENT_LIST_DIR}/decoder/pdf417.c
  ${CMAKE_CURRENT_LIST_DIR}/decoder/pdf417.h
#   ${CMAKE_CURRENT_LIST_DIR}/decoder/qr_finder.c
#   ${CMAKE_CURRENT_LIST_DIR}/decoder/qr_finder.h
#   ${CMAKE_CURRENT_LIST_DIR}/decoder/sq_finder.c
#   ${CMAKE_CURRENT_LIST_DIR}/decoder/sq_finder.h
  
  ${CMAKE_CURRENT_LIST_DIR}/processor/lock.c
  ${CMAKE_CURRENT_LIST_DIR}/processor/null.c
#   ${CMAKE_CURRENT_LIST_DIR}/processor/posix.c
#   ${CMAKE_CURRENT_LIST_DIR}/processor/posix.h
  ${CMAKE_CURRENT_LIST_DIR}/processor/win.c
#   ${CMAKE_CURRENT_LIST_DIR}/processor/x.c

#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/bch15_5.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/bch15_5.h
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/binarize.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/binarize.h
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/isaac.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/isaac.h
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/qrdec.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/qrdec.h
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/qrdectxt.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/rs.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/rs.h
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/util.c
#   ${CMAKE_CURRENT_LIST_DIR}/qrcode/util.h

#   ${CMAKE_CURRENT_LIST_DIR}/video/dshow.c
#   ${CMAKE_CURRENT_LIST_DIR}/video/null.c
#   ${CMAKE_CURRENT_LIST_DIR}/video/v4l.c
#   ${CMAKE_CURRENT_LIST_DIR}/video/v4l1.c
#   ${CMAKE_CURRENT_LIST_DIR}/video/v4l2.c
#   ${CMAKE_CURRENT_LIST_DIR}/video/vfw.c

#   ${CMAKE_CURRENT_LIST_DIR}/window/dib.c
#   ${CMAKE_CURRENT_LIST_DIR}/window/null.c
#   ${CMAKE_CURRENT_LIST_DIR}/window/vfw.c
#   ${CMAKE_CURRENT_LIST_DIR}/window/win.c
#   ${CMAKE_CURRENT_LIST_DIR}/window/win.h
#   ${CMAKE_CURRENT_LIST_DIR}/window/x.c
#   ${CMAKE_CURRENT_LIST_DIR}/window/x.h
#   ${CMAKE_CURRENT_LIST_DIR}/window/ximage.c
#   ${CMAKE_CURRENT_LIST_DIR}/window/xv.c
)

target_link_libraries(${PROJECT_NAME}
    $ENV{LIBGNUWIN32}/bin/jpeg62.dll
    $ENV{LIBGNUWIN32}/bin/libpng3.dll
    $ENV{LIBGNUWIN32}/bin/libpng12.dll
)