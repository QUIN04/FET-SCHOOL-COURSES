module librarya.librarya {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;

        requires org.controlsfx.controls;
                        requires org.kordamp.bootstrapfx.core;
            
    opens librarya.librarya to javafx.fxml;
    exports librarya.librarya;
}