/********************
GNU Radio C++ Flow Graph Source File

Title: Your First Flowgraph
GNU Radio version: 3.10.7.0
********************/

#include "sineWaveFlowgraph.hpp"

using namespace gr;


sineWaveFlowgraph::sineWaveFlowgraph ()
: QWidget() {

    this->setWindowTitle("Your First Flowgraph");
    // check_set_qss
    // set icon
    this->top_scroll_layout = new QVBoxLayout();
    this->setLayout(this->top_scroll_layout);
    this->top_scroll = new QScrollArea();
    this->top_scroll->setFrameStyle(QFrame::NoFrame);
    this->top_scroll_layout->addWidget(this->top_scroll);
    this->top_scroll->setWidgetResizable(true);
    this->top_widget = new QWidget();
    this->top_scroll->setWidget(this->top_widget);
    this->top_layout = new QVBoxLayout(this->top_widget);
    this->top_grid_layout = new QGridLayout();
    this->top_layout->addLayout(this->top_grid_layout);

    this->settings = new QSettings("GNU Radio", "sineWaveFlowgraph");

    this->tb = gr::make_top_block("Your First Flowgraph");

// Blocks:
        qtgui_time_sink_x_0 = qtgui::time_sink_c::make(
            1024, // size
            samp_rate, // samp_rate
            """", // name
            1 // number of inputs
        );

        QWidget* _qtgui_time_sink_x_0_win;
        qtgui_time_sink_x_0->set_update_time(0.10);
        qtgui_time_sink_x_0->set_y_axis(-1, 1);

        qtgui_time_sink_x_0->set_y_label("Amplitude", """");

        qtgui_time_sink_x_0->enable_tags(true);
        qtgui_time_sink_x_0->set_trigger_mode(gr::qtgui::TRIG_MODE_FREE, gr::qtgui::TRIG_SLOPE_POS, 0.0, 0,0, "");

        qtgui_time_sink_x_0->enable_autoscale(false);
        qtgui_time_sink_x_0->enable_grid(false);
        qtgui_time_sink_x_0->enable_axis_labels(true);
        qtgui_time_sink_x_0->enable_control_panel(false);
        qtgui_time_sink_x_0->enable_stem_plot(false);

        {
            std::string labels[10] = {"Signal 1", "Signal 2", "Signal 3", "Signal 4", "Signal 5",
                "Signal 6", "Signal 7", "Signal 8", "Signal 9", "Signal 10"};
            int widths[10] = {1, 1, 1, 1, 1,
                1, 1, 1, 1, 1};
            std::string colors[10] = {"blue", "red", "green", "black", "cyan",
                "magenta", "yellow", "dark red", "dark green", "dark blue"};
            double alphas[10] = {1.0, 1.0, 1.0, 1.0, 1.0,
                1.0, 1.0, 1.0, 1.0, 1.0};
            int markers[10] = {-1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1};
            int styles[10] = {1, 1, 1, 1, 1,
                1, 1, 1, 1, 1};

            for(int i=0; i <2; i++) {
                if (sizeof(labels[i]) == 0) {
                    if (i % 2 == 0)
                        qtgui_time_sink_x_0->set_line_label(i, "Re Data " + std::to_string(i));
                    else
                        qtgui_time_sink_x_0->set_line_label(i, "Im Data " + std::to_string(i));
                }
                else
                    qtgui_time_sink_x_0->set_line_label(i, labels[i]);

                qtgui_time_sink_x_0->set_line_width(i, widths[i]);
                qtgui_time_sink_x_0->set_line_color(i, colors[i]);
                qtgui_time_sink_x_0->set_line_style(i, styles[i]);
                qtgui_time_sink_x_0->set_line_marker(i, markers[i]);
                qtgui_time_sink_x_0->set_line_alpha(i, alphas[i]);
          }
        }

        _qtgui_time_sink_x_0_win = this->qtgui_time_sink_x_0->qwidget();

        top_layout->addWidget(_qtgui_time_sink_x_0_win);

        qtgui_freq_sink_x_0 = qtgui::freq_sink_c::make(
            1024, // size
            fft::window::WIN_BLACKMAN_hARRIS, // wintype
            0, // fc
            samp_rate, // bw
            """", // name
            1 // nconnections
        );

        QWidget* _qtgui_freq_sink_x_0_win;

        qtgui_freq_sink_x_0->set_update_time(0.10);
        qtgui_freq_sink_x_0->set_y_axis((-140), 10);
        qtgui_freq_sink_x_0->set_y_label("Relative Gain", "dB");
        qtgui_freq_sink_x_0->set_trigger_mode(gr::qtgui::TRIG_MODE_FREE, 0.0, 0, "");
        qtgui_freq_sink_x_0->enable_autoscale(false);
        qtgui_freq_sink_x_0->enable_grid(false);
        qtgui_freq_sink_x_0->set_fft_average(1.0);
        qtgui_freq_sink_x_0->enable_axis_labels(true);
        qtgui_freq_sink_x_0->enable_control_panel(false);


        {
            std::string labels[10] = {"", "", "", "", "",
                "", "", "", "", ""};
            int widths[10] = {1, 1, 1, 1, 1,
                1, 1, 1, 1, 1};
            std::string colors[10] = {"blue", "red", "green", "black", "cyan",
                "magenta", "yellow", "dark red", "dark green", "dark blue"};
            double alphas[10] = {1.0, 1.0, 1.0, 1.0, 1.0,
                1.0, 1.0, 1.0, 1.0, 1.0};
            for (int i = 0; i < 1; i++) {
                if (sizeof(labels[i]) == 0) {
                    qtgui_freq_sink_x_0->set_line_label(i, "Data " + std::to_string(i));
                } else {
                    qtgui_freq_sink_x_0->set_line_label(i, labels[i]);
                }
                qtgui_freq_sink_x_0->set_line_width(i, widths[i]);
                qtgui_freq_sink_x_0->set_line_color(i, colors[i]);
                qtgui_freq_sink_x_0->set_line_alpha(i, alphas[i]);
            }
        }
        _qtgui_freq_sink_x_0_win = this->qtgui_freq_sink_x_0->qwidget();

        top_layout->addWidget(_qtgui_freq_sink_x_0_win);

        this->blocks_throttle2_0 = blocks::throttle::make(sizeof(gr_complex) * 1, samp_rate, true, blocks_throttle2_0_limit(0.1));

        this->analog_sig_source_x_0 = analog::sig_source_c::make(samp_rate, analog::GR_COS_WAVE, 1000, 1, 0,0);


// Connections:
    this->tb->hier_block2::connect(this->analog_sig_source_x_0, 0, this->blocks_throttle2_0, 0);
    this->tb->hier_block2::connect(this->blocks_throttle2_0, 0, this->qtgui_freq_sink_x_0, 0);
    this->tb->hier_block2::connect(this->blocks_throttle2_0, 0, this->qtgui_time_sink_x_0, 0);
}

sineWaveFlowgraph::~sineWaveFlowgraph () {
}

// Callbacks:
int sineWaveFlowgraph::get_samp_rate () const {
    return this->samp_rate;
}

void sineWaveFlowgraph::set_samp_rate (int samp_rate) {
    this->samp_rate = samp_rate;
    this->analog_sig_source_x_0->set_sampling_freq(this->samp_rate);
    this->blocks_throttle2_0->set_sample_rate(this->samp_rate);
    this->qtgui_freq_sink_x_0->set_frequency_range(0, this->samp_rate);
    this->qtgui_time_sink_x_0->set_samp_rate(this->samp_rate);
}


int main (int argc, char **argv) {

    QApplication app(argc, argv);

    sineWaveFlowgraph* top_block = new sineWaveFlowgraph();

    top_block->tb->start();
    top_block->show();
    app.exec();


    return 0;
}
#include "moc_sineWaveFlowgraph.cpp"
