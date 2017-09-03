; Illustration of FFI usage
;
; (C) 2017 GNU General Public Licence
; Otto Linnemann

(ns example
  (:require
   [pixie.ffi :as ffi]
   [pixie.ffi-infer :refer :all]))


(with-config {:library "ffitest"
              :cxx-flags ["-I/usr/local/include/ffitest"]
              :includes ["ffitest.h"]}
  (defcfn init_ffitest)
  (defcfn kill_ffitest)
  (defcfn print_ffi)
  (defcfn set_ffi_params)
  (defcstruct ffitest_int_t [:s])
  (defcstruct ffitest_params_t
    [:i :l :f :lf :s :internal])
  (defccallback ffi_cb_t)
  (defcfn set_ffi_callback)
  (defcfn invoke_cb))


(def ffitest (init_ffitest))

(def internal
  (doto (ffitest_int_t)
    (ffi/set! :s "YYY")))

(def par
  (doto (ffitest_params_t)
    (ffi/set! :i 1)
    (ffi/set! :l 2)
    (ffi/set! :f 33.33)
    (ffi/set! :lf 44.44)
    (ffi/set! :s "XXX")
    (ffi/set! :internal internal)))

(set_ffi_params ffitest par)
(print_ffi ffitest)

(defn callback [p x]
  (println "*** invoked callback with: " x "! ***")
  (inc x))

(set_ffi_callback ffitest (ffi/ffi-prep-callback ffi_cb_t callback))
(invoke_cb ffitest 42)
