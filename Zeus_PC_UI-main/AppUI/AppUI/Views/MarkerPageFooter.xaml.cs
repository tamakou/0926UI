using System.Windows;
using System.Windows.Controls;
using AppUI.ViewModels;
using static AppUI.ViewModels.MarkerPageFooterViewModel;

namespace AppUI.Views;

/// <summary>
/// MarkerPageFooter.xaml の相互作用ロジック
/// </summary>
public partial class MarkerPageFooter : UserControl
{
    public MarkerPageFooter()
    {
        InitializeComponent();
        this.Unloaded += MarkerPageFooter_Unloaded;
    }
    private void MarkerPageFooter_Unloaded(object sender, RoutedEventArgs e)
    {
        if (DataContext is IDisposable disposable)
        {
            disposable.Dispose();
        }
    }
}
