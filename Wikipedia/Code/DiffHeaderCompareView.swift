
import UIKit

class DiffHeaderCompareView: UIView {

    @IBOutlet var contentView: UIView!
    @IBOutlet var fromItemView: DiffHeaderCompareItemView!
    @IBOutlet var toItemView: DiffHeaderCompareItemView!
    @IBOutlet var divView: UIView!
    @IBOutlet var innerHeightConstraint: NSLayoutConstraint!
    @IBOutlet var stackView: UIStackView!
    private var maxHeight: CGFloat = 0
    private var minHeight: CGFloat = 0
    
    private var beginSquishYOffset: CGFloat = 0
    private var scrollYOffset: CGFloat = 0
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        commonInit()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        commonInit()
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        maxHeight = stackView.frame.height
        minHeight = max(fromItemView.minHeight, toItemView.minHeight)

        configureHeight(beginSquishYOffset: beginSquishYOffset, scrollYOffset: scrollYOffset)
    }
    
    private func commonInit() {
        Bundle.main.loadNibNamed(DiffHeaderCompareView.wmf_nibName(), owner: self, options: nil)
            addSubview(contentView)
            contentView.frame = self.bounds
            contentView.autoresizingMask = [.flexibleHeight, .flexibleWidth]
    }
    
    func configureHeight(beginSquishYOffset: CGFloat, scrollYOffset: CGFloat) {
        
        self.beginSquishYOffset = beginSquishYOffset
        self.scrollYOffset = scrollYOffset
        
        let amountToSquish = scrollYOffset - beginSquishYOffset
        if amountToSquish >= 0 {
            innerHeightConstraint.constant = max((maxHeight - amountToSquish), minHeight)
        } else {
            innerHeightConstraint.constant = maxHeight
        }
    }
    
    func update(_ viewModel: DiffHeaderCompareViewModel) {
        
        fromItemView.update(viewModel.fromModel)
        toItemView.update(viewModel.toModel)
    }
    
    override func point(inside point: CGPoint, with event: UIEvent?) -> Bool {
        return false
    }
}

extension DiffHeaderCompareView: Themeable {
    func apply(theme: Theme) {
        backgroundColor = theme.colors.paperBackground
        contentView.backgroundColor = theme.colors.paperBackground
        divView.backgroundColor = theme.colors.chromeShadow
        fromItemView.apply(theme: theme)
        toItemView.apply(theme: theme)
    }
}
