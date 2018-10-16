art_make(
    LIBRARY_NAME
        anatool_Core
    LIB_LIBRARIES
        ${ART_FRAMEWORK_CORE}
        ${ART_FRAMEWORK_PRINCIPAL}
        ${ART_FRAMEWORK_SERVICES_REGISTRY}
        ${ART_FRAMEWORK_SERVICES_BASIC}
        ${ROOT_BASIC_LIB_LIST}
        lardataobj_RecoBase
        canvas
        cetlib cetlib_except
    )

install_headers()
install_source()
install_fhicl()
